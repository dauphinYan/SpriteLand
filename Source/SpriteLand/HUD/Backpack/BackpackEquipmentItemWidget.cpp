#include "BackpackEquipmentItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/Weapon/WeaponBase.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"

void UBackpackEquipmentItemWidget::OnUseButtonClicked()
{
	if (Info && EquipmentDataTable)
	{
		for (FName RowName : EquipmentDataTable->GetRowNames())
		{
			FEquipmentItemInfo* RowData = EquipmentDataTable->FindRow<FEquipmentItemInfo>(RowName, TEXT("Equipment Info"));
			if (RowData->ItemName == Info->ItemName)
			{

				// 找到目标行，先检查软引用的“路径”是否为空
				if (RowData->EquipmentClass.IsNull())
				{
					UE_LOG(LogTemp, Log, TEXT("EquipmentClass is null！"));
					return;
				}

				// 打印一下路径，方便调试
				UE_LOG(LogTemp, Log, TEXT("EquipmentClass path：%s"), *RowData->EquipmentClass.ToSoftObjectPath().ToString());

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
}
