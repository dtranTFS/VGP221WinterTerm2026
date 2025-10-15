// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectGameMode.h"

void AFPSProjectGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// 1. To print screen
	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameModeBase! This is hybrid Build"));

	// 2. To print console
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));

	// 3. Priting Values to console
	int TestNumber = 10;
	float TestFloat = 30.5f;
	bool TestBool = true;
	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, TestFloat: %f, TestBool: %i"), TestNumber, TestFloat, TestBool);

	int* NumPointer = &TestNumber;
	UE_LOG(LogTemp, Warning, TEXT("NumPointer as memory: %p"), NumPointer);
	UE_LOG(LogTemp, Warning, TEXT("NumPointer as num: %i"), NumPointer);
	UE_LOG(LogTemp, Warning, TEXT("NumPointer dereferenced: %i"), *NumPointer);

	// 4. Modern way of debugging valules
	UE_LOGFMT(LogTemp, Warning, "TestNumber: {0}, TestFloat: {1}, NameTest: {2}", TestNumber, TestFloat, "Danny");
}
