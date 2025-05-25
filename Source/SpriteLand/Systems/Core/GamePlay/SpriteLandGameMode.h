#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpriteLandGameMode.generated.h"

UCLASS()
class SPRITELAND_API ASpriteLandGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASpriteLandGameMode();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UEnemyManagerComponent* EnemyManager;

public:
	void RegisterEnemy(class AEnemyCharacterBase* Enemy);

	void UnregisterEnemy(AEnemyCharacterBase* Enemy);
};
