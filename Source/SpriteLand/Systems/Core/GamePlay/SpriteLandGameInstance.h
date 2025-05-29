#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpriteLand/Character/Common/CharacterInfo.h"
#include "SpriteLandGameInstance.generated.h"

UCLASS()
class SPRITELAND_API USpriteLandGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:


private:
	UPROPERTY(EditDefaultsOnly)
	EHeroName HeroName = EHeroName::Knight;

public:
	FORCEINLINE EHeroName GetHeroName() const { return HeroName; }
};
