#include "SkillComponent.h"

USkillComponent::USkillComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void USkillComponent::BeginPlay()
{
	Super::BeginPlay();

	if (SkillDataTable)
	{
		SkillInstance.Empty();
		for (FSkillInfo& SkillInfo : FSkillInfos)
		{
			for (auto& RowName : SkillDataTable->GetRowNames())
			{
				if (FSkillData* RowData = SkillDataTable->FindRow<FSkillData>(RowName, TEXT("Looking for skill data.")))
				{
					if (SkillInfo.SkillNameTag == RowData->SkillNameTag)
					{
						SkillInstance.Add(*RowData);
						break;
					}
				}
			}
		}
	}
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
			if (bCanUseSkill(SkillNameTag))
			{
				ChangeCharacterSkillByNameTag(SkillNameTag);
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

bool USkillComponent::bCanUseSkill(FGameplayTag SkillNameTag)
{
	return !bSkillOnCoolingDown(SkillNameTag) && bManaIsEnough(SkillNameTag);
}

bool USkillComponent::bManaIsEnough(FGameplayTag SkillNameTag)
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

void USkillComponent::ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag)
{
}

void USkillComponent::SkillBeginToCool(FGameplayTag SkillNameTag)
{

}

void USkillComponent::ActivateConsumeMana()
{
}

void USkillComponent::DeactivateConsumeMana()
{
}

