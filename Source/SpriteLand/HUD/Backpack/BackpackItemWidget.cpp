#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UBackpackItemWidget::UpdateViewInfo(const FItemInfoBase* Info, const int32 InCount)
{
	if (Info)
	{
		ItemImage->SetBrushResourceObject(Info->Icon);
		ItemNameText->SetText(Info->DisplayName);
		ItemDescText->SetText(Info->Description);
		ItemAmountText->SetText(FText::AsNumber(InCount));
	}
}
