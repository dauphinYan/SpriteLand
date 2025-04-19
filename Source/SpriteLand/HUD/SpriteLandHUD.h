#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpriteLandHUD.generated.h"


UCLASS()
class SPRITELAND_API ASpriteLandHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> BackpackWidgetClass;

	UPROPERTY()
	class UBackpackWidget* BackpackWidget;

	bool SetBackpackView();



};
