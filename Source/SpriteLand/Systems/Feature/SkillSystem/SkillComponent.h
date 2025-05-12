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
	UPROPERTY(EditDefaultsOnly)
	TArray<FSkillData> SkillInstance;

	TMap<FGameplayTag, bool> SkillCooldowns;

	virtual bool UseSkill(FGameplayTag SkillNameTag);

	virtual bool UpgradeSkill(FGameplayTag SkillNameTag);

	virtual bool UseSkillByButton(int32 Index);

	virtual bool bSkillOnCoolingDown(FGameplayTag SkillNameTag);

	virtual void SkillBeginToCool(FGameplayTag SkillNameTag);

public:
	FORCEINLINE TMap<FGameplayTag, bool>& GetSkillCooldowns() { return SkillCooldowns; }
};
