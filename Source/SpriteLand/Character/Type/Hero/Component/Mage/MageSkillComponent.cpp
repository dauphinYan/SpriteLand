#include "MageSkillComponent.h"

void UMageSkillComponent::ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag)
{
	if (SkillNameTag.MatchesTagExact(FGameplayTag::RequestGameplayTag(FName("Skill.Name.Hero.Fireball"))))
	{

	}
}
