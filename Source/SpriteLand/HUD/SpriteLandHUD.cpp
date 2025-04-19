#include "SpriteLandHUD.h"
#include "Backpack/BackpackWidget.h"

void ASpriteLandHUD::BeginPlay()
{
	Super::BeginPlay();

	if (BackpackWidgetClass)
	{
		APlayerController* PlayerController = GetOwningPlayerController();
		BackpackWidget = CreateWidget<UBackpackWidget>(PlayerController, BackpackWidgetClass);
	}
}

bool ASpriteLandHUD::SetBackpackView()
{
	if (BackpackWidget == nullptr)
	{
		if (BackpackWidgetClass)
		{
			APlayerController* PlayerController = GetOwningPlayerController();
			BackpackWidget = CreateWidget<UBackpackWidget>(PlayerController, BackpackWidgetClass);
		}
	}

	if (BackpackWidget == nullptr) return false;

	if (BackpackWidget->IsInViewport())
	{
		BackpackWidget->RemoveFromViewport();
		return false;
	}
	else
	{
		BackpackWidget->AddToViewport();
		return true;
	}
}

