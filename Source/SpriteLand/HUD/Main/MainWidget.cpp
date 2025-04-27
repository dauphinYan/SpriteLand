#include "MainWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "BossHealthBarWidget.h"

void UMainWidget::InitializeBossHealthBar(FText BossName, float HealthPercent)
{
	if (BossHealthBarWidget)
	{
		BossHealthBarWidget->NameText->SetText(BossName);
		BossHealthBarWidget->HealthBar->SetPercent(HealthPercent);
		BossHealthBarWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void UMainWidget::UpdateBossHealthBar(float HealthPercent)
{
	if (BossHealthBarWidget)
	{
		BossHealthBarWidget->HealthBar->SetPercent(HealthPercent);
	}
}

void UMainWidget::HideBossHealthBar()
{
	if (BossHealthBarWidget)
	{
		BossHealthBarWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}
