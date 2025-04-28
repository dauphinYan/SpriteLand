#pragma once

#include "CoreMinimal.h"
#include "CharacterInfo.generated.h"

UENUM(BlueprintType)
enum class EHeroName : uint8
{
	Knight
};

//UENUM(BlueprintType)
//enum class ESpriteName : uint8
//{
//
//};

UENUM(BlueprintType)
enum class EEnemyName : uint8
{
	AnonymousThief,
	AbyssalKing,
	ShadowReaver,
	IronTyrant
};

USTRUCT(BlueprintType)
struct FCharacterInfoBase :public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefenseValue;
};

USTRUCT(BlueprintType)
struct FEnemyInfo : public FCharacterInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEnemyName EnemyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackSpeed;
};