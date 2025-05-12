#include "SkillComponent.h"

USkillComponent::USkillComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void USkillComponent::BeginPlay()
{
	Super::BeginPlay();

}

void USkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool USkillComponent::UseSkill(FGameplayTag SkillNameTag)
{
	for (int32 i = 0; i < SkillInstance.Num(); ++i)
	{
		if (SkillInstance[i].SkillNameTag == SkillNameTag)
		{
			if (!bSkillOnCoolingDown(SkillNameTag))
			{
				SkillBeginToCool(SkillInstance[i].SkillNameTag);
				return true;
			}
			break;
		}
	}
	return false;
}

bool USkillComponent::UpgradeSkill(FGameplayTag SkillNameTag)
{
	return false;
}

bool USkillComponent::UseSkillByButton(int32 Index)
{
	return false;
}

bool USkillComponent::bSkillOnCoolingDown(FGameplayTag SkillNameTag)
{
	if (SkillCooldowns.Find(SkillNameTag))
	{
		return SkillCooldowns[SkillNameTag];
	}
	return true;
}

void USkillComponent::SkillBeginToCool(FGameplayTag SkillNameTag)
{

}

