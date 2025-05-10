#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuffInterface.generated.h"

UINTERFACE(MinimalAPI)
class UBuffInterface : public UInterface
{
	GENERATED_BODY()
};

class SPRITELAND_API IBuffInterface
{
	GENERATED_BODY()

public:
	virtual void RestoreHealth(float InValue);
};
