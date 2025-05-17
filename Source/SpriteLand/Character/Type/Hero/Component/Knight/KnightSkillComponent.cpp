#include "KnightSkillComponent.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacters/KnightCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../EquipmentComponent.h"

void UKnightSkillComponent::ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag)
{
	if (SkillNameTag.MatchesTagExact(FGameplayTag::RequestGameplayTag(FName("Skill.Name.Hero.WhirlwindSlash"))))
	{
		KnightCharacter = Cast<AKnightCharacter>(HeroCharacter);
		if (KnightCharacter)
		{
			if (KnightCharacter->GetKnightSkill() == EKnightSkill::WhirlwindSlash)
			{
				KnightCharacter->SetKnightSkill(EKnightSkill::None);
				KnightCharacter->GetEquipmentComponent()->WeaponAttackEnd();
				KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
			}
			else
			{
				KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
				KnightCharacter->SetKnightSkill(EKnightSkill::WhirlwindSlash);
				KnightCharacter->GetEquipmentComponent()->WeaponAttackStart();
			}
		}
	}
}
