#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"


UCLASS()
class SPRITELAND_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitializeBossHealthBar(FText BossName, float HealthPercent);
	void UpdateBossHealthBar(float HealthPercent);
	void HideBossHealthBar();

private:
	UPROPERTY(meta = (BindWidget))
	class UBossHealthBarWidget* BossHealthBarWidget;


};
