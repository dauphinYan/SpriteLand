#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.generated.h"

UENUM(BlueprintType)
enum class EItemName : uint8
{
	Unknown,
	LongSword_Wood,
	LongSword_Iron,
	LongSword_Diamond,
	HealthPotion_Small,
	ManaPotion_Small,
	Apple,
	Banana,
	Pear
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Unknown,
	Consumable, // 消耗品
	Equipment, // 装备
	Quest, // 任务道具
	Miscellaneous // 杂项
};

UENUM(BlueprintType)
enum class EConsumableEffectType : uint8
{
	Unknown,
	RestoreHP,
	RestoreMP,
	AddExperience
};

USTRUCT(BlueprintType)
struct FItemInfoBase :public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStackSize;
};

USTRUCT(BlueprintType)
struct FConsumableItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EConsumableEffectType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float EffectValue;

};

USTRUCT(BlueprintType)
struct FEquipmentItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefensiveValue;

};