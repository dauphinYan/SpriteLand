#include "HeroAnimInstance.h"
#include "HeroCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AHeroCharacterBase>(TryGetPawnOwner());
	if (Character)
	{
		MovementComponent = Character->GetCharacterMovement();
	}
}

void UHeroAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	if (Character == nullptr)
	{
		Character = Cast<AHeroCharacterBase>(TryGetPawnOwner());
		if (Character == nullptr)
			return;
	}

	if (MovementComponent)
	{
		Velocity = Character->GetVelocity();
		GroundSpeed = UKismetMathLibrary::VSizeXY(Velocity);
		bIsFalling = MovementComponent->IsFalling();
		bShouldMove = (!MovementComponent->GetCurrentAcceleration().IsZero() && GroundSpeed > 3.f);
	}
}
