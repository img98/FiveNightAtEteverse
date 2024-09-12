// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MonsterAIController.h"

AMonsterAIController::AMonsterAIController()
{
}

void AMonsterAIController::BeginPlay()
{
	Super::BeginPlay();

	ensure(BTAsset);
	RunBehaviorTree(BTAsset);
}

