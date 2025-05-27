#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpriteLandGameMode.generated.h"

class AHeroCharacterBase;

class AEnemyCharacterBase;
class UEnemyManagerComponent;

UCLASS()
class SPRITELAND_API ASpriteLandGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASpriteLandGameMode();

protected:
	virtual void StartPlay() override;

protected:
	void SpawnPlayerCharacter();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<AHeroCharacterBase> KnightCharacterClass;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<AHeroCharacterBase> MageCharacterClass;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<AHeroCharacterBase> RogueCharacterClass;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<AHeroCharacterBase> BarbarianCharacterClass;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEnemyManagerComponent* EnemyManager;

public:
	void RegisterEnemy(AEnemyCharacterBase* Enemy);

	void UnregisterEnemy(AEnemyCharacterBase* Enemy);
};
