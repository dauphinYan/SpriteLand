#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"
#include "EquipmentItemWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"


void UBackpackItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

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
	}
}

void UBackpackItemWidget::UpdateViewInfo(FEquipmentItemInfo* InInfo, const int32 InCount)
{
	if (InInfo)
	{
		Info = InInfo;
		ItemImage->SetBrushResourceObject(InInfo->Icon);
		ItemNameText->SetText(InInfo->DisplayName);
		ItemDescText->SetText(InInfo->Description);
		ItemAmountText->SetText(FText::AsNumber(InCount));

		if (EquipmentItemWidgetClass) {
			auto TempWidget = CreateWidget<UEquipmentItemWidget>(this, EquipmentItemWidgetClass);
			TempWidget->UpdateInfo(InInfo);
			ExtraInfoBox->AddChild(TempWidget);
		}
	}
}

void UBackpackItemWidget::OnUseButtonClicked()
{
	if (Info)
	{
		switch (Info->ItemType)
		{
		case EItemType::Equipment:
			FEquipmentItemInfo* TempInfo = static_cast<FEquipmentItemInfo*>(Info);
			if (TempInfo)
			{
				UClass* LoadedClass = TempInfo->EquipmentClass.LoadSynchronous();
				if (LoadedClass)
				{
					APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
					ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(PlayerPawn);
					if (Interface)
					{
						Interface->Equip(GetWorld()->SpawnActor<AEquipmentBase>(LoadedClass));
					}
				}
			}
			break;
		}
	}
}