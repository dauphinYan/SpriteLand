#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Systems/Feature/SkillSystem/SkillComponent.h"
#include "HeroSkillComponent.generated.h"


UCLASS()
class SPRITELAND_API UHeroSkillComponent : public USkillComponent
{
	GENERATED_BODY()

	friend class AHeroCharacterBase;

protected:
	AHeroCharacterBase* HeroCharacter;
	
};
