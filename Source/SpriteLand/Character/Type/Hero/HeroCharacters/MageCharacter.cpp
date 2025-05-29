#include "MageCharacter.h"
#include "../Component/Mage/MageSkillComponent.h"

AMageCharacter::AMageCharacter()
{
	SkillComponent = CreateDefaultSubobject<UMageSkillComponent>(TEXT("SkillComponent"));
}

void AMageCharacter::SetMageSkill(EMageSkill InMageSkill)
{
	MageSkill = InMageSkill;
}
