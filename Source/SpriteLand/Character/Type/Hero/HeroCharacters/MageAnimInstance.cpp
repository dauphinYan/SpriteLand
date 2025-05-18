#include "MageAnimInstance.h"
#include "MageCharacter.h"

void UMageAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (Character)
	{
		MageCharacter = Cast<AMageCharacter>(Character);
	}
}
