#include "SkillInterface.h"

bool ISkillInterface::UseSkill(FGameplayTag SkillNameTag)
{
	return false;
}

bool ISkillInterface::UpgradeSkill(FGameplayTag SkillNameTag)
{
	return false;
}

bool ISkillInterface::UseSkillByButton(int32 Index)
{
	return false;
}
