#include "HeroBuffComponent.h"
#include "../HeroCharacterBase.h"

void UHeroBuffComponent::RestoreHealth(float InValue)
{
	HeroCharacter->CurHealth = FMath::Min(HeroCharacter->CurHealth + InValue, HeroCharacter->HealthTotal);
}
