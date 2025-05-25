#include "SpriteLandGameMode.h"
#include "SpriteLand/Systems/Feature/EnemySystem/EnemyManagerComponent.h"


ASpriteLandGameMode::ASpriteLandGameMode()
{
	EnemyManager = CreateDefaultSubobject<UEnemyManagerComponent>(TEXT("EnemyManager"));
}

void ASpriteLandGameMode::RegisterEnemy(AEnemyCharacterBase* Enemy)
{
	if (EnemyManager)
	{
		EnemyManager->RegisterEnemy(Enemy);
	}
}

void ASpriteLandGameMode::UnregisterEnemy(AEnemyCharacterBase* Enemy)
{
	if (EnemyManager)
	{
		EnemyManager->UnregisterEnemy(Enemy);
	}
}

