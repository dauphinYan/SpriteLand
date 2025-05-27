#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpriteLand/Character/Type/Hero/HeroInfo.h"
#include "SpriteLandGameInstance.generated.h"

UCLASS()
class SPRITELAND_API USpriteLandGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:


private:
	UPROPERTY(EditDefaultsOnly)
	EHeroClass HeroClass = EHeroClass::Knight;

public:
	FORCEINLINE EHeroClass GetHeroClass() const { return HeroClass; }
};
