#include "MainWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "BossHealthBarWidget.h"
#include "../Battle/HeroInfoWidget.h"
#include "../Battle/ComboWidget.h"
#include "SpriteLand/Systems/Feature/SkillSystem/SkillInfo.h"
#include "Components/CanvasPanelSlot.h"

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

void UMainWidget::UpdateHeroHealthBar(float CurHealth, float TotalHealth)
{
	if (HeroInfoWidget)
		HeroInfoWidget->UpdateHeroHealthBar(CurHealth, TotalHealth);
}

void UMainWidget::UpdateHeroManaBar(float CurMana, float TotalMana)
{
	if (HeroInfoWidget)
		HeroInfoWidget->UpdateHeroManaBar(CurMana, TotalMana);
}

void UMainWidget::UpdateHeroSkillData(TArray<FSkillData> SkillDatas)
{
	if (HeroInfoWidget)
	{
		HeroInfoWidget->UpdateHeroSkillData(SkillDatas);
	}
}

void UMainWidget::UseSkill(FGameplayTag SkillNameTag)
{
	if (HeroInfoWidget)
	{
		HeroInfoWidget->PlayCoolingDownAnimation(SkillNameTag);
	}
}

void UMainWidget::AddCombo()
{
	if (ComboWidget)
	{
		ComboWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
		ComboWidget->AddCombo();
	}
}

void UMainWidget::LockingTarget(FVector2D& ScreenPosition)
{

	if (!LockOnMarkWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("LockOnMarkWidget Î´³õÊ¼»¯"));
		return;
	}

	LockOnMarkWidget->SetVisibility(ESlateVisibility::Visible);

	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(LockOnMarkWidget->Slot))
	{
		CanvasSlot->SetPosition(ScreenPosition);
	}
}
