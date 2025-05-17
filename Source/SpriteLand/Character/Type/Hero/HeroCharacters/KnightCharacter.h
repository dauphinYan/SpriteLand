#pragma once

#include "CoreMinimal.h"
#include "../HeroCharacterBase.h"
#include "KnightCharacter.generated.h"

UENUM(BlueprintType)
enum class EKnightSkill : uint8
{
	None,
	WhirlwindSlash
};

UCLASS()
class SPRITELAND_API AKnightCharacter : public AHeroCharacterBase
{
	GENERATED_BODY()

public:
	AKnightCharacter();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EKnightSkill KnightSkill = EKnightSkill::None;

public:
	void SetKnightSkill(EKnightSkill InKnightSkill);

public:
	FORCEINLINE const EKnightSkill& GetKnightSkill() { return KnightSkill; }
};
