#include "HeroInfoWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "SpriteLand/Systems/Feature/SkillSystem/SkillInfo.h"
#include"SpriteLand/Character/Type/Hero/HeroCharacterBase.h"
#include "SpriteLand/Character/Type/Hero/Component/HeroSkillComponent.h"

void UHeroInfoWidget::UpdateHeroHealthBar(float CurHealth, float TotalHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurHealth / TotalHealth);
		HealthText->SetText(FText::AsNumber(CurHealth));
	}
}

void UHeroInfoWidget::UpdateHeroManaBar(float CurMana, float TotalMana)
{
	if (ManaBar)
	{
		ManaBar->SetPercent(CurMana / TotalMana);
		ManaText->SetText(FText::AsNumber(CurMana));
	}
}

void UHeroInfoWidget::UpdateHeroSkillData(TArray<FSkillData> InSkillDatas)
{
	SkillDatas = InSkillDatas;

	if (SkillDatas.IsValidIndex(0) && SkillImage_1)
	{
		SkillImage_1->SetBrushResourceObject(SkillDatas[0].Icon);
	}
	if (SkillDatas.IsValidIndex(1) && SkillImage_2)
	{
		SkillImage_2->SetBrushResourceObject(SkillDatas[1].Icon);
	}
}


void UHeroInfoWidget::PlayCoolingDownAnimation(FGameplayTag SkillNameTag)
{
	HeroCharacter = HeroCharacter == nullptr ? Cast<AHeroCharacterBase>(GetOwningPlayer()->GetPawn()) : HeroCharacter;
	int32 CurIndex = HeroCharacter->GetSkillComponent()->GetSkillIndex(SkillNameTag);
	if (CurIndex > 2) return;

	switch (CurIndex)
	{
	case 0:
	{
		if (CoolingDown1)
		{
			float CooldownTime = SkillDatas[CurIndex].Cooldown;

			if (CooldownTimerHandles.Contains(CurIndex))
			{
				GetWorld()->GetTimerManager().ClearTimer(CooldownTimerHandles[CurIndex]);
			}
			else
			{
				CooldownTimerHandles.Add(CurIndex, FTimerHandle());
			}

			PlayAnimation(CoolingDown1, 0.f, 1, EUMGSequencePlayMode::Forward, 1 / CooldownTime);

			GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandles[CurIndex], this, &UHeroInfoWidget::OnCoolingDownFinished, CooldownTime, false);
		}
	}
	default:
		break;
	}


}

void UHeroInfoWidget::OnCoolingDownFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("¿‰»¥∂Øª≠≤•∑≈ÕÍ±œ"));
}
