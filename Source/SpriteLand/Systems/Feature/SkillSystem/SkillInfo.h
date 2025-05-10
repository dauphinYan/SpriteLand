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
	//TSubclassOf<class AEffectBase> EffectClass; // 特效或技能行为类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayTag> SkillTags; // 可用于判断技能类型（AOE、Buff、Dot等）
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
	TArray<FString> AdditionalEffects; // 描述性或效果标签，比如“眩晕”、“穿透”等
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
//    // 动态计算技能属性
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
