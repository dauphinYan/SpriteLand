#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SkillInfo.generated.h"

USTRUCT(BlueprintType)
struct FSkillLevelData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAddtion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownReduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer SkillTypeTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayTag> SkillEffectTags;
};

USTRUCT(BlueprintType)
struct FSkillData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ManaCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag SkillNameTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSkillLevelData> SkillLevelData;
};