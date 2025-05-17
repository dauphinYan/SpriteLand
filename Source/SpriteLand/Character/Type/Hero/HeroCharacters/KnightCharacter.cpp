#include "KnightCharacter.h"
#include "SpriteLand/Character/Type/Hero/Component/Knight/KnightSkillComponent.h"

AKnightCharacter::AKnightCharacter()
{
	SkillComponent = CreateDefaultSubobject<UKnightSkillComponent>(TEXT("SkillComponent"));
}

void AKnightCharacter::SetKnightSkill(EKnightSkill InKnightSkill)
{
	KnightSkill = InKnightSkill;
}
