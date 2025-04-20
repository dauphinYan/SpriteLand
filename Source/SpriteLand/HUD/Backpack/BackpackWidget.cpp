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

void UBackpackWidget::InitializeItemInfoCache()
{
	auto LoadTable = [&](UDataTable* Table)
		{
			if (!Table) return;

			static const FString ContextString(TEXT("ItemInfoCache"));

			for (auto& RowName : Table->GetRowNames())
			{
				if (FItemInfoBase* Row = Table->FindRow<FItemInfoBase>(RowName, ContextString))
				{
					ItemInfoCache.Add(Row->ItemName, Row);
				}
			}
		};

	LoadTable(WeaponDataTable);
	LoadTable(ConsumableDataTable);
}

void UBackpackWidget::RefreshBackpackView_Equip()
{
	if (BackpackComponent == nullptr) return;
	const auto Items = BackpackComponent->GetEquipmentItems();
	EquipItemWrapBox->ClearChildren();

	for (const auto Pair : Items)
	{
		EItemName ItemName = Pair.Key;
		int32 Count = Pair.Value.Count;

		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
		if (!InfoPtr) return;
		FItemInfoBase* Info = *InfoPtr;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(Info, Count);
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
		EItemName ItemName = Pair.Key;
		int32 Count = Pair.Value;

		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
		if (!InfoPtr) return;
		FItemInfoBase* Info = *InfoPtr;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(Info, Count);
		ConsumableItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

void UBackpackWidget::RefreshBackpackView_Miscellaneous()
{
	if (BackpackComponent == nullptr) return;
	const auto Items = BackpackComponent->GetMiscellaneousItems();
	MiscellaneousItemWrapBox->ClearChildren();

	for (const auto Pair : Items)
	{
		EItemName ItemName = Pair.Key;
		int32 Count = Pair.Value;

		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
		if (!InfoPtr) return;
		FItemInfoBase* Info = *InfoPtr;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(Info, Count);
		MiscellaneousItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

FItemInfoBase* UBackpackWidget::FindItemInfoInTables(EItemName ItemName)
{
	return nullptr;
}