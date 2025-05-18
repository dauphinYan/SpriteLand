#pragma once

#include "CoreMinimal.h"
#include "../HeroAnimInstance.h"
#include "MageAnimInstance.generated.h"

UCLASS()
class SPRITELAND_API UMageAnimInstance : public UHeroAnimInstance
{
	GENERATED_BODY()
	
protected:
	virtual void NativeInitializeAnimation() override;

protected:
	UPROPERTY(BlueprintReadOnly)
	class AMageCharacter* MageCharacter;
};
