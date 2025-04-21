#include "EquipmentItemWidget.h"
#include "Components/TextBlock.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"

void UEquipmentItemWidget::UpdateInfo(FEquipmentItemInfo* Info)
{
	AttackText->SetText(FText::AsNumber(Info->AttackValue));
	DefenceText->SetText(FText::AsNumber(Info->DefensiveValue));
}
