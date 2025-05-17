#include "ComboWidget.h"
#include "Components/TextBlock.h"

void UComboWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateComboText();
}

void UComboWidget::AddCombo()
{
	ComboCount++;
	UpdateComboText();

	if (ExpandAnimation)
	{
		PlayAnimation(ExpandAnimation, 0.f, 1, EUMGSequencePlayMode::Forward, 1.0f, false);
	}

	GetWorld()->GetTimerManager().ClearTimer(ComboResetTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(ComboResetTimerHandle, this, &UComboWidget::ResetCombo, ComboResetTime, false);

}

void UComboWidget::ResetCombo()
{
	ComboCount = 0;
	UpdateComboText();
	SetVisibility(ESlateVisibility::Hidden);
}

void UComboWidget::UpdateComboText()
{
	if (ComboCountText)
	{
		ComboCountText->SetText(FText::AsNumber(ComboCount));
	}
}