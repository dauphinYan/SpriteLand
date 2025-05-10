#include "BackpackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacterBase.h"

void UBackpackWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	WeaponSlot->BackpackWidget = this;
}

void UBackpackWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerController = Cast<ASpriteLandPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController != nullptr)
	{
		BackpackComponent = PlayerController->GetBackpackComponent();
	}

	UpdateCharacterInfo();
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

		FEquipmentItemInfo** InfoPtr = BackpackComponent->GetEquipmentItemInfoCache().Find(ItemName);
		if (!InfoPtr || !ItemWidgetClass) return;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(*InfoPtr, Count);
		ItemWidget->BackpackWidget = this;
		EquipItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

void UBackpackWidget::RefreshBackpackView_Consumable()
{
	if (BackpackComponent == nullptr) return;
	const auto Items = BackpackComponent->GetComsumableItems();
	ConsumableItemWrapBox->ClearChildren();

	for (const auto Pair : Items)
	{
		EConsumableItemName ItemName = Pair.Key;
		int32 Count = Pair.Value;

		FConsumableItemInfo** InfoPtr = BackpackComponent->GetConsumableItemInfoCache().Find(ItemName);
		if (!InfoPtr && ItemWidgetClass) return;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->BackpackWidget = this;
		ItemWidget->UpdateViewInfo(*InfoPtr, Count);
		ConsumableItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

void UBackpackWidget::UpdateCharacterInfo()
{
	HeroCharacter = HeroCharacter == nullptr ? Cast<AHeroCharacterBase>(PlayerController->GetCharacter()) : HeroCharacter;
	if (HeroCharacter)
	{
		AttackValueText->SetText(FText::AsNumber(HeroCharacter->AttackValueTotal));
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