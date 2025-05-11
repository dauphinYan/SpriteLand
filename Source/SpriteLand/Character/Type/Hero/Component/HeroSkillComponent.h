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
	virtual void BeginPlay() override;

public:
	void UpdateSkillData();

	int32 GetSkillIndex(FGameplayTag SkillNameTag);

protected:
	AHeroCharacterBase* HeroCharacter;

	virtual void SkillBeginToCool(FGameplayTag SkillNameTag) override;

	virtual bool UseSkillByButton(int32 Index) override;
};
