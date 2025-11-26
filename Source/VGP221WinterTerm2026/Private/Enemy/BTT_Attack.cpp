// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_Attack.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	// Method 1: Build in Damage System
	AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::ApplyDamage(player, 1.0f, AIController, AIController->GetPawn(), UDamageType::StaticClass());

	// Method 2: Calling damage function
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->OnHurtPlayer(5.0f);

	// Method 3: Using Pawn
	// AEnemyAICharacter* enemyCharacter = Cast<AEnemyAICharacter>(AIController->GetPawn());
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->OnHurtPlayer(enemyCharacter->DamageAmount);

	// Method 4: Using Blackboard
	// float BBDamageAmount = OwnerComp.GetBlackboardComponent()->GetValueAsFloat("BBDamageAmount");
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->OnHurtPlayer(BBDamageAmount);

	return EBTNodeResult::Succeeded;
}
