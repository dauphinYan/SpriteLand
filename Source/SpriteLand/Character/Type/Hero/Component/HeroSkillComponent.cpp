#include "HeroSkillComponent.h"
#include "EquipmentComponent.h"
#include "../HeroCharacterBase.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/HUD/SpriteLandHUD.h"
#include "../HeroCharacters/KnightCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UHeroSkillComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateSkillData();
}

void UHeroSkillComponent::UpdateSkillData()
{
	if (HeroCharacter && HeroCharacter->PlayerController)
	{
		HeroCharacter->PlayerController->GetSpriteLandHUD()->UpdateHeroSkillData(SkillInstance);
		for (auto SkillData : SkillInstance)
		{
			SkillCooldowns.Add({ SkillData.SkillNameTag,false });
		}
	}
}

int32 UHeroSkillComponent::GetSkillIndex(FGameplayTag SkillNameTag)
{
	for (int i = 0; i < SkillInstance.Num(); ++i)
	{
		if (SkillNameTag == SkillInstance[i].SkillNameTag)
		{
			return i;
		}
	}

	return 10;
}

void UHeroSkillComponent::SkillBeginToCool(FGameplayTag SkillNameTag)
{
	if (HeroCharacter && HeroCharacter->PlayerController)
	{
		for (int32 i = 0; i < SkillInstance.Num(); ++i)
		{
			if (SkillInstance[i].SkillNameTag == SkillNameTag)
			{
				HeroCharacter->PlayerController->GetSpriteLandHUD()->UseSkill(SkillNameTag);
				SkillCooldowns[SkillNameTag] = true;
				break;
			}
		}
	}
}

bool UHeroSkillComponent::UseSkillByButton(int32 Index)
{
	if (SkillInstance.IsValidIndex(Index))
	{
		if (UseSkill(SkillInstance[Index].SkillNameTag))
		{
			return true;
		}
		
	}

	return false;
}

void UHeroSkillComponent::ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag)
{
	if (SkillNameTag.MatchesTagExact(FGameplayTag::RequestGameplayTag(FName("Skill.Name.Hero.Whirlwind"))))
	{
		AKnightCharacter* KnightCharacter = Cast<AKnightCharacter>(HeroCharacter);
		if (KnightCharacter)	
		{
			KnightCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
			KnightCharacter->SetKnightSkill(EKnightSkill::WhirlWind);
			KnightCharacter->GetEquipmentComponent()->WeaponAttackStart();
		}
	}
}
