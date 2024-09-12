// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/BTT_SetCurrentState.h"
#include "Enum/MonsterState.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_SetCurrentState::UBTT_SetCurrentState()
{
}
//Task를 C++로 만들수 있지만 BT도 블루프린트로 다루니 BTT도 블루프린트에서 구현하기로 결정했다. SetCurrentState까지만 C++로 쓰자.
EBTNodeResult::Type UBTT_SetCurrentState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsEnum(CurrentState.SelectedKeyName, (uint8)NextState);
	return EBTNodeResult::Succeeded;
}
