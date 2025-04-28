#include "BackpackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WrapBox.h"
#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"

void UBackpackWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	InitializeItemInfoCache();
}

void UBackpackWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerController = Cast<ASpriteLandPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController != nullptr)
	{
		BackpackComponent = PlayerController->GetBackpackComponent();
	}
}

template <typename ItemNameType, typename ItemType>
auto LoadTable = [&](UDataTable* Table, TMap<ItemNameType, ItemType*>& Cache)
	{
		if (!Table) return;

		for (auto& RowName : Table->GetRowNames())
		{
			if (ItemType* Row = Table->FindRow<ItemType>(RowName, TEXT("ItemInfoCache")))
			{
				Cache.Add(Row->ItemName, Row);
			}
		}
	};

void UBackpackWidget::InitializeItemInfoCache()
{
	LoadTable<EEquipmentItemName, FEquipmentItemInfo>(WeaponDataTable, EquipmentItemInfoCache);
	LoadTable<EConsumableItemName, FConsumableItemInfo>(ConsumableDataTable, ConsumableItemInfoCache);
}

void UBackpackWidget::RefreshBackpackView_Equip()
{
	if (BackpackComponent == nullptr) return;
	const auto Items = BackpackComponent->GetEquipmentItems();
	EquipItemWrapBox->ClearChildren();

	for (const auto Pair : Items)
	{
		EEquipmentItemName ItemName = Pair.Key;
		int32 Count = Pair.Value.Count;

		FEquipmentItemInfo** InfoPtr = EquipmentItemInfoCache.Find(ItemName);
		if (!InfoPtr) return;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(*InfoPtr, Count);
		EquipItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

void UBackpackWidget::RefreshBackpackView_Consumable()
{
	if (BackpackComponent == nullptr) return;
	const auto Items = BackpackComponent->GetComsumbleItems();
	ConsumableItemWrapBox->ClearChildren();

	for (const auto Pair : Items)
	{
		EConsumableItemName ItemName = Pair.Key;
		int32 Count = Pair.Value;

		FConsumableItemInfo** InfoPtr = ConsumableItemInfoCache.Find(ItemName);
		if (!InfoPtr) return;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(*InfoPtr, Count);
		ConsumableItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

//void UBackpackWidget::RefreshBackpackView_Miscellaneous()
//{
//	if (BackpackComponent == nullptr) return;
//	const auto Items = BackpackComponent->GetMiscellaneousItems();
//	MiscellaneousItemWrapBox->ClearChildren();
//
//	for (const auto Pair : Items)
//	{
//		EItemName ItemName = Pair.Key;
//		int32 Count = Pair.Value;
//
//		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
//		if (!InfoPtr) return;
//		FItemInfoBase* Info = *InfoPtr;
//
//		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
//		ItemWidget->UpdateViewInfo(Info, Count);
//		MiscellaneousItemWrapBox->AddChildToWrapBox(ItemWidget);
//	}
//}

//FItemInfoBase* UBackpackWidget::FindItemInfoInTables(EItemName ItemName)
//{
//	return nullptr;
//}