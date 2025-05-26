#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillInfo.h"
#include "SkillComponent.generated.h"

USTRUCT(BlueprintType)
struct FSkillInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayTag SkillNameTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Level;
};

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
	TArray<FSkillData> SkillInstance;

	UPROPERTY(EditDefaultsOnly)
	TArray<FSkillInfo> FSkillInfos;

	TMap<FGameplayTag, bool> SkillCooldowns;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* SkillDataTable;

	virtual bool UseSkill(FGameplayTag SkillNameTag);

	virtual bool UpgradeSkill(FGameplayTag SkillNameTag);

	virtual bool UseSkillByButton(int32 Index); // ���ڰ������Ƽ����ͷ�

	virtual bool bCanUseSkill(FGameplayTag SkillNameTag);

	virtual bool bManaIsEnough(FGameplayTag SkillNameTag);

	virtual bool bSkillOnCoolingDown(FGameplayTag SkillNameTag);

	virtual void ChangeCharacterSkillByNameTag(FGameplayTag SkillNameTag); // �ı��ɫ״̬������״̬����ѡ���ɫ����

	virtual void SkillBeginToCool(FGameplayTag SkillNameTag);

protected:
	float ManaCostPerSecond = 10.f;

	FTimerHandle ManaConsumeTimer;

	UFUNCTION()
	virtual void ActivateConsumeMana();

	UFUNCTION()
	virtual void DeactivateConsumeMana();

public:
	FORCEINLINE TMap<FGameplayTag, bool>& GetSkillCooldowns() { return SkillCooldowns; }
};
