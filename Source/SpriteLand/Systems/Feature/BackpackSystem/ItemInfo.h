#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.generated.h"

UENUM(BlueprintType)
enum class EItemQuality : uint8
{
	White,
	Green,
	Blue,
	Purple,
	Orange,
	Black,
	Red
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
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStackSize;
};

UENUM(BlueprintType)
enum class EConsumableItemName : uint8
{
	HealthPotion_Small,
	ManaPotion_Small,
	Apple,
	Banana,
	Pear
};

USTRUCT(BlueprintType)
struct FConsumableItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EConsumableItemName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EConsumableEffectType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float EffectValue;

};

UENUM(BlueprintType)
enum class EEquipmentItemName : uint8
{
	LongSword_Wood,
	LongSword_Iron,
	LongSword_Diamond,
	Wand_Wood,
};


UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	Weapon,
	Helmet,
	Armor,
	Boot
};

UENUM(BlueprintType)
enum class EProfessionType : uint8
{
	Knight,
	Mage,
	Rogue,
};

USTRUCT(BlueprintType)
struct FEquipmentItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEquipmentItemName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEquipmentType EquipmentType;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	EProfessionType ProfessionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefenseValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<class AEquipmentBase> EquipmentClass;
};