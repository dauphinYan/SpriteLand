#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "HeroInfoWidget.generated.h"


UCLASS()
class SPRITELAND_API UHeroInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateHeroHealthBar(float CurHealth, float TotalHealth);

	void UpdateHeroManaBar(float CurMana, float TotalMana);

	void UpdateHeroSkillData(TArray<struct FSkillData> InSkillDatas);

	void PlayCoolingDownAnimation(FGameplayTag SkillNameTag);

	void OnCoolingDownFinished();

private:
	TArray<FSkillData> SkillDatas;

	TMap<int32, FTimerHandle> CooldownTimerHandles;

	class AHeroCharacterBase* HeroCharacter;
private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ManaBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaText;

	UPROPERTY(meta = (BindWidget))
	class UImage* SkillImage_1;

	UPROPERTY(meta = (BindWidget))
	UImage* SkillImage_2;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* CoolingDown1;
};
