#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ComboWidget.generated.h"


UCLASS()
class SPRITELAND_API UComboWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ComboCountText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* ExpandAnimation;

public:
	virtual void NativeConstruct() override;

	void AddCombo();

	UFUNCTION()
	void ResetCombo();

private:
	void UpdateComboText();

private:
	int32 ComboCount = 0;

	FTimerHandle ComboResetTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Combo")
	float ComboResetTime = 3.0f;
};
