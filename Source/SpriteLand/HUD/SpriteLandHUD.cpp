#include "SpriteLandHUD.h"
#include "Backpack/BackpackWidget.h"
#include "Main/MainWidget.h"

void ASpriteLandHUD::BeginPlay()
{
	Super::BeginPlay();

	if (BackpackWidgetClass)
	{
		APlayerController* PlayerController = GetOwningPlayerController();
		BackpackWidget = CreateWidget<UBackpackWidget>(PlayerController, BackpackWidgetClass);
	}

	if (MainWidgetClass)
	{
		APlayerController* PlayerController = GetOwningPlayerController();
		MainWidget = CreateWidget<UMainWidget>(PlayerController, MainWidgetClass);
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
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

void ASpriteLandHUD::InitializeBossHealthBar(FText BossName, float HealthPercent)
{
	if (MainWidget)
	{
		MainWidget->InitializeBossHealthBar(BossName, HealthPercent);
	}
}

void ASpriteLandHUD::UpdateBossHealthBar(float HealthPercent)
{
	if (MainWidget)
	{
		MainWidget->UpdateBossHealthBar(HealthPercent);
	}
}

void ASpriteLandHUD::HideBossHealthBar()
{
	if (MainWidget)
	{
		MainWidget->HideBossHealthBar();
	}
}

