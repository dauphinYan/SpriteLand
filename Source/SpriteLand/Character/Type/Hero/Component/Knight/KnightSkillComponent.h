#pragma once

#include "CoreMinimal.h"
#include "../HeroSkillComponent.h"
#include "KnightSkillComponent.generated.h"


UCLASS()
class SPRITELAND_API UKnightSkillComponent : public UHeroSkillComponent
{
	GENERATED_BODY()

protected:
	virtual void ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag) override;

	class AKnightCharacter* KnightCharacter;
	
protected:
	virtual void ActivateConsumeMana() override;

	virtual void DeactivateConsumeMana() override;
};
