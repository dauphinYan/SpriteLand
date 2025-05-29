#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "FireBallProjectile.generated.h"

UCLASS()
class SPRITELAND_API AFireBallProjectile : public AProjectile
{
	GENERATED_BODY()

public:
	AFireBallProjectile();

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	class UNiagaraComponent* FireNiagara;

protected:
	virtual void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
