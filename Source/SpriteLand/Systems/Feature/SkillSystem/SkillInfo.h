#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SkillInfo.generated.h"

USTRUCT(BlueprintType)
struct FSkillData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SkillName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ManaCost;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSubclassOf<class AEffectBase> EffectClass; // ��Ч������Ϊ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayTag> SkillTags; // �������жϼ������ͣ�AOE��Buff��Dot�ȣ�
};

USTRUCT(BlueprintType)
struct FSkillUpgradeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UpgradeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownReduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> AdditionalEffects; // �����Ի�Ч����ǩ�����硰ѣ�Ρ�������͸����
};

//USTRUCT(BlueprintType)
//struct FSkillInstance
//{
//    GENERATED_BODY()
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite)
//    FSkillData BaseData;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite)
//    FSkillUpgradeData UpgradeData;
//
//    // ��̬���㼼������
//    float GetFinalDamage() const
//    {
//        return BaseData.Damage * UpgradeData.DamageMultiplier;
//    }
//
//    float GetFinalCooldown() const
//    {
//        return BaseData.Cooldown - UpgradeData.CooldownReduction;
//    }
//};
