#include "EnemyCharacterBase.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"

AEnemyCharacterBase::AEnemyCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	
}

void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	OnTakeAnyDamage.AddDynamic(this, &AEnemyCharacterBase::ReceiveDamage);
}

void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyCharacterBase::ReceiveDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser)
{
	UGameplayStatics::SpawnSoundAtLocation(
		GetWorld(),
		HurtSound,
		GetActorLocation()
	);
}



