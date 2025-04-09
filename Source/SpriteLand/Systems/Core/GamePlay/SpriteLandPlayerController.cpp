#include "SpriteLandPlayerController.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"

ASpriteLandPlayerController::ASpriteLandPlayerController()
{
	BackpackComponent = CreateDefaultSubobject<UBackpackComponent>(TEXT("Backpack Component"));
}

void ASpriteLandPlayerController::BeginPlay()
{
	Super::BeginPlay();


}
