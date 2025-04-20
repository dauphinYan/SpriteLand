#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"


void UBackpackItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (UseButton)
	{
		UseButton->OnClicked.AddDynamic(this, &UBackpackItemWidget::OnUseButtonClicked);
	}
}

void UBackpackItemWidget::OnUseButtonClicked()
{

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
	}
}

