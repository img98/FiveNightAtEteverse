// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enum/MonsterState.h"
#include "BTT_SetCurrentState.generated.h"

 //Task를 C++로 만들수 있지만 BT도 블루프린트로 다루니 BTT도 블루프린트에서 구현하기로 결정했다. SetCurrentState까지만 C++로 쓰자.
UCLASS(Blueprintable, BlueprintType)
class FIVENIGHTATETEVERSE_API UBTT_SetCurrentState : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTT_SetCurrentState();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	FBlackboardKeySelector CurrentState;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	EMonsterState NextState;
};
