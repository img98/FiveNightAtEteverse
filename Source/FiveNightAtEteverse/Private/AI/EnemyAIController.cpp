// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	check(BTAsset);
	RunBehaviorTree(BTAsset);
}

