#include "EnemyCharacterBase.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

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
	if (HurtSound)
	{
		UGameplayStatics::SpawnSoundAtLocation(
			GetWorld(),
			HurtSound,
			GetActorLocation()
		);
	}

	int32 IntDamage = FMath::RoundToInt(Damage);
	if (IntDamage <= 0)
	{
		return;
	}

	TArray<int32> Digits;
	while (IntDamage > 0)
	{
		Digits.Insert(IntDamage % 10, 0);
		IntDamage /= 10;
	}

	if (!DamageFloatNiagara)
	{
		return;
	}

	const float OffsetX = 20.0f;
	for (int32 i = 0; i < Digits.Num(); ++i)
	{
		UNiagaraComponent* DigitEffect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			DamageFloatNiagara,
			GetActorLocation() + FVector(OffsetX * i, 0.f, 100.f),
			FRotator::ZeroRotator,
			FVector(1.f)
		);

		if (DigitEffect)
		{
			DigitEffect->SetVariableInt(FName("DigitCount"), Digits[i]);
		}
	}
}
