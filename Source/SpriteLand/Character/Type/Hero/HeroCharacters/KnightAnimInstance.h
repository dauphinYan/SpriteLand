#pragma once

#include "CoreMinimal.h"
#include "../HeroAnimInstance.h"
#include "KnightAnimInstance.generated.h"

UCLASS()
class SPRITELAND_API UKnightAnimInstance : public UHeroAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	class AKnightCharacter* KnightCharacter;


};
