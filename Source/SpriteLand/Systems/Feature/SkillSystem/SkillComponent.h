#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillInfo.h"
#include "SkillComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRITELAND_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USkillComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	TMap<FGameplayTag, FSkillData> SkillInstance;

	virtual bool UseSkill(FGameplayTag SkillNameTag);

	virtual bool UpgradeSkill(FGameplayTag SkillNameTag);

	virtual bool bSkillOnCoolingDown(FGameplayTag SkillNameTag);
};
