#include "SpriteLandGameMode.h"
#include "SpriteLandGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SpriteLand/Systems/Feature/EnemySystem/EnemyManagerComponent.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacterBase.h"

ASpriteLandGameMode::ASpriteLandGameMode()
{
	EnemyManager = CreateDefaultSubobject<UEnemyManagerComponent>(TEXT("EnemyManager"));
}

void ASpriteLandGameMode::StartPlay()
{
	Super::StartPlay();

	SpawnPlayerCharacter();
}

void ASpriteLandGameMode::SpawnPlayerCharacter()
{
	UWorld* World = GetWorld();
	if (!World) return;

	USpriteLandGameInstance* GI = Cast<USpriteLandGameInstance>(GetGameInstance());
	if (!GI) return;

	EHeroName HeroName = GI->GetHeroName();
	TSubclassOf<AHeroCharacterBase> CharacterToSpawn = nullptr;

	switch (HeroName)
	{
	case EHeroName::Knight:
		CharacterToSpawn = KnightCharacterClass;
		break;
	case EHeroName::Mage:
		CharacterToSpawn = MageCharacterClass;
		break;
	case EHeroName::Rogue:
		CharacterToSpawn = RogueCharacterClass;
		break;
	case EHeroName::BarBarain:
		CharacterToSpawn = BarbarianCharacterClass;
		break;
	default:
		CharacterToSpawn = KnightCharacterClass;
		break;
	}

	if (CharacterToSpawn)
	{
		FVector SpawnLocation = FVector::ZeroVector;
		FRotator SpawnRotation = FRotator::ZeroRotator;

		AActor* PlayerStart = FindPlayerStart(GetWorld()->GetFirstPlayerController());
		if (PlayerStart)
		{
			SpawnLocation = PlayerStart->GetActorLocation();
			SpawnRotation = PlayerStart->GetActorRotation();
		}

		AHeroCharacterBase* SpawnedCharacter = World->SpawnActor<AHeroCharacterBase>(CharacterToSpawn, SpawnLocation, SpawnRotation);
		if (SpawnedCharacter)
		{
			AController* PC = UGameplayStatics::GetPlayerController(World, 0);
			if (PC)
			{
				PC->Possess(SpawnedCharacter);
			}
		}
	}
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

