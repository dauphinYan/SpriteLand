#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayTagContainer.h"
#include "SpriteLandHUD.generated.h"


UCLASS()
class SPRITELAND_API ASpriteLandHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	bool SetBackpackView();

	void InitializeBossHealthBar(FText BossName, float HealthPercent);

	void UpdateBossHealthBar(float HealthPercent);

	void HideBossHealthBar();

	void UpdateCharacterHealthBar(float CurHealth, float TotalHealth);

	void UpdateCharacterManaBar(float CurMana, float TotalMana);

	void UpdateHeroSkillData(TArray<struct FSkillData> SkillDatas);

	void UseSkill(FGameplayTag SkillNameTag);

	void AddCombo();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UBackpackWidget> BackpackWidgetClass;

	UPROPERTY()
	UBackpackWidget* BackpackWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UMainWidget> MainWidgetClass;

	UPROPERTY()
	UMainWidget* MainWidget;

public:
	FORCEINLINE UBackpackWidget* GetBackpackWidget() const { return BackpackWidget; }
	FORCEINLINE UMainWidget* GetMainWidget() const { return MainWidget; }
};
