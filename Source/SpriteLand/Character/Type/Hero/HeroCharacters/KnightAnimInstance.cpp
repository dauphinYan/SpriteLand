#include "KnightAnimInstance.h"
#include "KnightCharacter.h"

void UKnightAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (Character)
	{
		KnightCharacter = Cast<AKnightCharacter>(Character);
	}
}

void UKnightAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);


}

