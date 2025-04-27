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

void UBackpackItemWidget::OnUseButtonClicked()
{
	if (Info)
	{
		switch (Info->ItemType)
		{
		case EItemType::Equipment:
			if (Info && EquipmentDataTable)
			{
				for (FName RowName : EquipmentDataTable->GetRowNames())
				{
					FEquipmentItemInfo* RowData = EquipmentDataTable->FindRow<FEquipmentItemInfo>(RowName, TEXT("Equipment Info"));
					if (RowData->ItemName == Info->ItemName)
					{
						if (RowData->EquipmentClass.IsNull())
						{
							UE_LOG(LogTemp, Log, TEXT("EquipmentClass is null."));
							return;
						}

						UClass* LoadedClass = RowData->EquipmentClass.LoadSynchronous();
						if (LoadedClass)
						{
							APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
							ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(PlayerPawn);
							if (Interface)
							{
								Interface->Equip(GetWorld()->SpawnActor<AEquipmentBase>(LoadedClass));
							}
						}
						break;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void UBackpackItemWidget::UpdateViewInfo(FItemInfoBase* InInfo, const int32 InCount)
{
	if (InInfo)
	{
		this->Info = InInfo;
		ItemImage->SetBrushResourceObject(Info->Icon);
		ItemNameText->SetText(Info->DisplayName);
		ItemDescText->SetText(Info->Description);
		ItemAmountText->SetText(FText::AsNumber(InCount));

		switch (Info->ItemType)
		{
		case EItemType::Equipment:
			FirstButtonText->SetText(FText::FromString(TEXT("装备")));
			if (EquipmentDataTable)
			{
				for (FName RowName : EquipmentDataTable->GetRowNames())
				{
					FEquipmentItemInfo* RowData = EquipmentDataTable->FindRow<FEquipmentItemInfo>(RowName, TEXT("Equipment Info"));
					if (RowData->ItemName == Info->ItemName)
					{
						if (EquipmentItemWidgetClass) {
							auto TempWidget = CreateWidget<UEquipmentItemWidget>(this, EquipmentItemWidgetClass);
							TempWidget->UpdateInfo(RowData);
							ExtraInfoBox->AddChild(TempWidget);
						}
						break;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}