// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/BTT_SetCurrentState.h"
#include "Enum/MonsterState.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_SetCurrentState::UBTT_SetCurrentState()
{
}
//Task�� C++�� ����� ������ BT�� �������Ʈ�� �ٷ�� BTT�� �������Ʈ���� �����ϱ�� �����ߴ�. SetCurrentState������ C++�� ����.
EBTNodeResult::Type UBTT_SetCurrentState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsEnum(CurrentState.SelectedKeyName, (uint8)NextState);
	return EBTNodeResult::Succeeded;
}
