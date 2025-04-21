// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemExtraWidget.generated.h"


UCLASS()
class SPRITELAND_API UItemExtraWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateInfo(FText Des,FText Value);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DesText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ValueText;
};
