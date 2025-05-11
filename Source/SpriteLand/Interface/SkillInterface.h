#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "SkillInterface.generated.h"

UINTERFACE(MinimalAPI)
class USkillInterface : public UInterface
{
	GENERATED_BODY()
};

class SPRITELAND_API ISkillInterface
{
	GENERATED_BODY()

public:
	virtual bool UseSkill(FGameplayTag SkillNameTag);

	virtual bool UpgradeSkill(FGameplayTag SkillNameTag);

	virtual bool UseSkillByButton(int32 Index);
};
