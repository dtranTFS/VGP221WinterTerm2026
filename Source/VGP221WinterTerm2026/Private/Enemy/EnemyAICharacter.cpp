// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAICharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Player/FPSCharacter.h"

// Sets default values
AEnemyAICharacter::AEnemyAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAICharacter::BeginPlay()
{
	Super::BeginPlay();

	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Player)
	{
		Player->OnPlayerDied.AddDynamic(this, &AEnemyAICharacter::HandlePlayerDied);
	}
}

// Called every frame
void AEnemyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAICharacter::OnDamage(float damage)
{
	Health -= damage;

	if (Health <= 0) {
		Destroy();
	}
}

void AEnemyAICharacter::HandlePlayerDied()
{
	Destroy();
}
