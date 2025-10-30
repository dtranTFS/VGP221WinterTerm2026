// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/GameHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VGP221WINTERTERM2026_API SSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwningHUD)
	SLATE_ARGUMENT(int, MyInt);
	SLATE_END_ARGS()

	TWeakObjectPtr<class AGameHUD> OwningHUD;
	int MyInt;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;

	/*
		--- Smart Pointer Cheat Sheet ---
		
		Unique Pointer: TUniquePtr<T> = TUniquePtr<int> Score;
			- Sole ownership of an object
			- Cannot be copied, only moved
			- Automatically deallocates memory when it goes out of scope
			- Resource management for single ownership scenarios

		Shared Pointer: TSharedPtr<T> = TSharedPtr<int> Score;
			- Multiple ownership of an object
				- Can be copied, increasing reference count
				- Automatically deallocates memory when the last reference is gone
				- Eg. UI Widgets, Game Objects shared across systems

		Weak Pointer: TWeakPtr<T> = TWeakPtr<int> Score;
		- Non-owning reference to an object managed by TSharedPtr
			- Does not affect reference count
			- Can be converted to TSharedPtr if the object is still valid
			- Prevents circular references and memory leaks
			- Temporary access to memory

		SoftObjectPtr<T>: TSoftObjectPtr<UTexture> TextureRef;
		- Reference to an asset that may not be loaded in memory
			- Can be serialized and saved as a reference
			- Loads the asset on demand
			- Useful for large assets or optional content
		*/
};
