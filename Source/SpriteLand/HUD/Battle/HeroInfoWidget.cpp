#include "HeroInfoWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHeroInfoWidget::UpdateCharacterHealthBar(float CurHealth, float TotalHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurHealth / TotalHealth);
		HealthText->SetText(FText::AsNumber(CurHealth));
	}
}

void UHeroInfoWidget::UpdateCharacterManaBar(float CurMana, float TotalMana)
{
	if (ManaBar)
	{
		ManaBar->SetPercent(CurMana / TotalMana);
		ManaText->SetText(FText::AsNumber(CurMana));
	}
}
