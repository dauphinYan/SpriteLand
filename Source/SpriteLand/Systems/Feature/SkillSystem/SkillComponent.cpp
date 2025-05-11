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
	if (SkillInstance.Find(SkillNameTag) && !bSkillOnCoolingDown(SkillNameTag))
	{
		return true;
	}
	return false;
}

bool USkillComponent::UpgradeSkill(FGameplayTag SkillNameTag)
{
	return false;
}

bool USkillComponent::bSkillOnCoolingDown(FGameplayTag SkillNameTag)
{
	return false;
}

