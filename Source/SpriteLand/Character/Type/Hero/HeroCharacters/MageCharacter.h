#pragma once

#include "CoreMinimal.h"
#include "../HeroCharacterBase.h"
#include "MageCharacter.generated.h"

UENUM(BlueprintType)
enum class EMageSkill :uint8
{
	None
};

UCLASS()
class SPRITELAND_API AMageCharacter : public AHeroCharacterBase
{
	GENERATED_BODY()

public:
	void SetMageSkill(EMageSkill InMageSkill);

private:
	EMageSkill MageSkill = EMageSkill::None;

public:
	FORCEINLINE EMageSkill GetMageSkill() { return MageSkill; }

};
