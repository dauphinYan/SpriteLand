#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Character/Common/BuffComponent.h"
#include "HeroBuffComponent.generated.h"

UCLASS()
class SPRITELAND_API UHeroBuffComponent : public UBuffComponent
{
	GENERATED_BODY()

	friend class AHeroCharacterBase;

private:
	UPROPERTY()
	class AHeroCharacterBase* HeroCharacter;

protected:
	void RestoreHealth(float InValue);

	void RestoreMana(float InValue);

protected:
	FTimerHandle RestoreHealthTimer;

	FTimerHandle RestoreManaTimer;
};
