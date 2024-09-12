// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enum/MonsterState.h"
#include "BTT_SetCurrentState.generated.h"

 //Task�� C++�� ����� ������ BT�� �������Ʈ�� �ٷ�� BTT�� �������Ʈ���� �����ϱ�� �����ߴ�. SetCurrentState������ C++�� ����.
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
