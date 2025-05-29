#include "FireBallProjectile.h"
#include "NiagaraComponent.h"

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

}
