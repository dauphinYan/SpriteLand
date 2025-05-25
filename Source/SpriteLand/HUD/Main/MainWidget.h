#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "MainWidget.generated.h"


UCLASS()
class SPRITELAND_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitializeBossHealthBar(FText BossName, float HealthPercent);

	void UpdateBossHealthBar(float HealthPercent);

	void HideBossHealthBar();

	void UpdateHeroHealthBar(float CurHealth, float TotalHealth);

	void UpdateHeroManaBar(float CurMana, float TotalMana);

	void UpdateHeroSkillData(TArray<struct FSkillData> SkillDatas);

	void UseSkill(FGameplayTag SkillNameTag);

	void AddCombo();

private:
	UPROPERTY(meta = (BindWidget))
	class UBossHealthBarWidget* BossHealthBarWidget;

	UPROPERTY(meta = (BindWidget))
	class UHeroInfoWidget* HeroInfoWidget;

	UPROPERTY(meta = (BindWidget))
	class UComboWidget* ComboWidget;
};
