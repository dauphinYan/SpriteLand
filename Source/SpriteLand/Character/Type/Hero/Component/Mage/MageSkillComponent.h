#pragma once

#include "CoreMinimal.h"
#include "../HeroSkillComponent.h"
#include "MageSkillComponent.generated.h"

UCLASS()
class SPRITELAND_API UMageSkillComponent : public UHeroSkillComponent
{
	GENERATED_BODY()
	
public:
	virtual void ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag) override;


};
