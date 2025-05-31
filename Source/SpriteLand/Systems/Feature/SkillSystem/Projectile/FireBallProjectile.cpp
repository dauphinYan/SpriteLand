#include "FireBallProjectile.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"

#include "SpriteLand/Character/Type/Enemy/EnemyCharacterBase.h"

AFireBallProjectile::AFireBallProjectile()
{
	FireNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("FireNigara"));
	FireNiagara->SetupAttachment(RootComponent);
}

void AFireBallProjectile::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(6.f);
}

void AFireBallProjectile::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OtherActor);
		if (Enemy)
		{
			UGameplayStatics::ApplyDamage(
				Enemy,
				10.f,
				Owner->GetInstigatorController(),
				Owner,
				UDamageType::StaticClass()
			);
		}
	}

	Super::OnBoxOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
