#include "EnemyManagerComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "Kismet/GameplayStatics.h"

UEnemyManagerComponent::UEnemyManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UEnemyManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UEnemyManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UEnemyManagerComponent::RegisterEnemy(AEnemyCharacterBase* Enemy)
{
	if (PlayerController == nullptr)
	{
		PlayerController = Cast<ASpriteLandPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	}

	if (PlayerController)
	{
		PlayerController->RegisterEnemy(Enemy);
	}
}

void UEnemyManagerComponent::UnregisterEnemy(AEnemyCharacterBase* Enemy)
{
	if (PlayerController == nullptr)
	{
		PlayerController = Cast<ASpriteLandPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	}

	if (PlayerController)
	{
		PlayerController->UnregisterEnemy(Enemy);
	}
}

