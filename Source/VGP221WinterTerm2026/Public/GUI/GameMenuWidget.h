// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GUI/ButtonWidget.h"
#include "GameMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTERTERM2026_API UGameMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimerText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ButtonContainer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ButtonWidgetClass;

	UFUNCTION()
	void UpdateHealthBar(float HealthPercent);

	UFUNCTION()
	void SetScoreText(int amount);

	UFUNCTION()
	void SetTimerText(int timer);



private:
	int UIScore; // Probably should put this game mode or score manager
};
