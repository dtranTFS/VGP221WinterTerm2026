// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "GUI/GameMenuWidget.h"
#include "GUI/SlateExample/SSettingsWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTERTERM2026_API AGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;

public:
	virtual void BeginPlay() override;

	// 1. HUD method of Making UI
	virtual void DrawHUD() override;

	// 2. Slates method of making UI
	TSharedPtr<class SSettingsWidget> SettingsWidget;
	TSharedPtr<class SWidget> SettingsWidgetContainer;

	void ShowSettingsMenu();
	void HideSettingsMenu();

	// 3. UMG method of making UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameMenuWidget> StartingGameWidget;
	UGameMenuWidget* GameMenuWidgetContainer;

	void SpawnGameMenu(TSubclassOf<UGameMenuWidget> NewGameMenuWidget);
};
