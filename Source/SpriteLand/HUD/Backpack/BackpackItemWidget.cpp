#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/Interface/BuffInterface.h"
#include "BackpackWidget.h"
#include "EquipmentItemWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

void UBackpackItemWidget::NativeOnInitialized()
{
	if (bIsInBackpack)
	{
		FirstButtonText->SetText(FText::FromString(TEXT("装备")));
		ItemImage->SetVisibility(ESlateVisibility::Visible);
		ItemAmountText->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		ItemImage->SetVisibility(ESlateVisibility::Hidden);
		ItemAmountText->SetVisibility(ESlateVisibility::Hidden);
		FirstButtonText->SetText(FText::FromString(TEXT("卸下")));
	}
}

void UBackpackItemWidget::UpdateViewInfo(FConsumableItemInfo* InInfo, const int32 InCount)
{
	if (InInfo)
	{
		Info = InInfo;
		ItemImage->SetBrushResourceObject(InInfo->Icon);
		ItemNameText->SetText(InInfo->DisplayName);
		ItemDescText->SetText(InInfo->Description);
		ItemAmountText->SetText(FText::AsNumber(InCount));
		FirstButtonText->SetText(FText::FromString(TEXT("使用")));
	}
}

void UBackpackItemWidget::UpdateViewInfo(FEquipmentItemInfo* InInfo, const int32 InCount)
{
	if (!InInfo) return;
	Info = InInfo;
	ItemImage->SetBrushResourceObject(Info->Icon);
	ItemNameText->SetText(Info->DisplayName);
	ItemDescText->SetText(Info->Description);
	ItemAmountText->SetText(FText::AsNumber(InCount));

	if (EquipmentItemWidgetClass) {
		auto TempWidget = CreateWidget<UEquipmentItemWidget>(this, EquipmentItemWidgetClass);
		TempWidget->UpdateInfo(InInfo);
		ExtraInfoBox->ClearChildren();
		ExtraInfoBox->AddChild(TempWidget);
	}
}

void UBackpackItemWidget::OnUseButtonClicked()
{
	if (!Info) return;
	if (bIsInBackpack) // 在背包区域
	{
		switch (Info->ItemType)
		{
		case EItemType::Equipment:
		{
			FEquipmentItemInfo* EquipmentInfo = static_cast<FEquipmentItemInfo*>(Info);
			if (EquipmentInfo && BackpackWidget->BackpackComponent->UseItem(EquipmentInfo->ItemName))
			{
				BackpackWidget->WeaponSlot->UpdateViewInfo(EquipmentInfo, 1);
				BackpackWidget->WeaponSlot->ItemImage->SetVisibility(ESlateVisibility::Visible);
				BackpackWidget->WeaponSlot->bIsFilled = true;
				BackpackWidget->UpdateCharacterInfo();
			}
			break;
		}
		case EItemType::Consumable:
		{
			FConsumableItemInfo* ConsumableInfo = static_cast<FConsumableItemInfo*>(Info);
			if (!ConsumableInfo) return;

			break;
		}
		}
	}
	else // 在装备区域
	{
		switch (Info->ItemType)
		{
		case EItemType::Equipment:
		{
			FEquipmentItemInfo* EquipmentInfo = static_cast<FEquipmentItemInfo*>(Info);
			if (EquipmentInfo && BackpackWidget->BackpackComponent->UnEquip(EquipmentInfo->ItemName))
			{
				ItemImage->SetVisibility(ESlateVisibility::Hidden);
				bIsFilled = false;
				if (BackpackWidget)
					BackpackWidget->UpdateCharacterInfo();
			}
			break;
		}
		}
	}
}