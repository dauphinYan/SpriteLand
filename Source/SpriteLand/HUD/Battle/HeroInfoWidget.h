#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeroInfoWidget.generated.h"


UCLASS()
class SPRITELAND_API UHeroInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateCharacterHealthBar(float CurHealth, float TotalHealth);

	void UpdateCharacterManaBar(float CurMana, float TotalMana);

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ManaBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaText;
};
