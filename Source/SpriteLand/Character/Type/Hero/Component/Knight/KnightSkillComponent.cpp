#include "KnightSkillComponent.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacters/KnightCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../EquipmentComponent.h"

void UKnightSkillComponent::ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag)
{
	if (SkillNameTag.MatchesTagExact(FGameplayTag::RequestGameplayTag(FName("Skill.Name.Hero.Knight.WhirlwindSlash"))))
	{
		KnightCharacter = KnightCharacter == nullptr ? Cast<AKnightCharacter>(HeroCharacter) : KnightCharacter;
		if (KnightCharacter)
		{
			if (KnightCharacter->GetKnightSkill() == EKnightSkill::WhirlwindSlash)
			{
				KnightCharacter->SetKnightSkill(EKnightSkill::None);
				KnightCharacter->GetEquipmentComponent()->WeaponAttackEnd();
				KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;

				GetWorld()->GetTimerManager().ClearTimer(ManaConsumeTimer);
			}
			else
			{
				KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
				KnightCharacter->SetKnightSkill(EKnightSkill::WhirlwindSlash);
				KnightCharacter->GetEquipmentComponent()->WeaponAttackStart();

				for (FSkillData SkillData : SkillInstance)
				{
					if (SkillData.SkillNameTag == SkillNameTag)
					{
						ManaCostPerSecond = SkillData.ManaCost;
						GetWorld()->GetTimerManager().SetTimer(ManaConsumeTimer, this, &UKnightSkillComponent::ActivateConsumeMana, 1.f, true);
						break;
					}
				}
			}
		}
	}
	if (SkillNameTag.MatchesTagExact(FGameplayTag::RequestGameplayTag(FName("SKill.Name.Hero.Knight.LanceCharge"))))
	{
		KnightCharacter = Cast<AKnightCharacter>(HeroCharacter);
		if (KnightCharacter)
		{
			if (KnightCharacter->GetKnightSkill() == EKnightSkill::LanceCharge)
			{
				KnightCharacter->SetKnightSkill(EKnightSkill::None);
			}
			else
			{
				KnightCharacter->SetKnightSkill(EKnightSkill::LanceCharge);
			}
		}
	}
}

void UKnightSkillComponent::ActivateConsumeMana()
{
	KnightCharacter = KnightCharacter == nullptr ? Cast<AKnightCharacter>(HeroCharacter) : KnightCharacter;
	if (!KnightCharacter) return;
	
	KnightCharacter->CurMana -= ManaCostPerSecond;

	if (KnightCharacter->CurMana <= 0)
	{
		DeactivateConsumeMana();
		GetWorld()->GetTimerManager().ClearTimer(ManaConsumeTimer);
		KnightCharacter->CurMana = 0;
	}

	Super::ActivateConsumeMana();
}

void UKnightSkillComponent::DeactivateConsumeMana()
{
	KnightCharacter->SetKnightSkill(EKnightSkill::None);
	KnightCharacter->GetEquipmentComponent()->WeaponAttackEnd();
	KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
}
