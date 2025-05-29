#include "Wand.h"
#include "SpriteLand/Systems/Feature/SkillSystem/Projectile/FireBallProjectile.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacterBase.h"

#include "Camera/CameraComponent.h"

void AWand::AttackStart()
{
	AHeroCharacterBase* HeroCharacter = Cast<AHeroCharacterBase>(GetOwner());
	check(HeroCharacter);


	// get target location.
	FHitResult HitResult;
	FVector TraceStart = HeroCharacter->GetCameraComponent()->GetComponentLocation();
	FVector TraceEnd = TraceStart + HeroCharacter->GetCameraComponent()->GetForwardVector() * 10000.f;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);

	FVector TargetLocation;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, TraceParams))
	{
		TargetLocation = HitResult.ImpactPoint;
	}
	else
	{
		TargetLocation = TraceEnd;
	}

	// spawn fireball.
	FVector MuzzleLocation = EquipmentMesh->GetSocketLocation("muzzle");
	FRotator MuzzleDirection = (TargetLocation - MuzzleLocation).GetSafeNormal().Rotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetOwner();

	if (FireBallClass)
	{
		AFireBallProjectile* FireBall = GetWorld()->SpawnActor<AFireBallProjectile>(
			FireBallClass, MuzzleLocation, MuzzleDirection, SpawnParams);
	}
}
