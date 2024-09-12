// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MonsterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, meta = (CannotImplementInterfaceInBlueprint)) 
class UMonsterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FIVENIGHTATETEVERSE_API IMonsterInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//UINTERFACE�� meta = (CannotImplementInterfaceInBlueprint)�� �߰��ϴ� BlueprintCallable�� ����� �� �־���.
	UFUNCTION(BlueprintCallable)
	virtual bool CheckPlayerStateSafe() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void SetCurrentState(EMonsterState InState) = 0; //�� EMonsterState�� include�ϰų� ���漱�� ���� �ʾƵ� �����ϴ°�?->�ǻ���� �ƴϰ� ���ڰ��̶� ������.
	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerSuccess() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerFail() = 0;
};
