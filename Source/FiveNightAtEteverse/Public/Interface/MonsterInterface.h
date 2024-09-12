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
	//UINTERFACE에 meta = (CannotImplementInterfaceInBlueprint)를 추가하니 BlueprintCallable을 사용할 수 있었다.
	UFUNCTION(BlueprintCallable)
	virtual bool CheckPlayerStateSafe() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void SetCurrentState(EMonsterState InState) = 0; //왜 EMonsterState를 include하거나 전방선언 하지 않아도 성공하는가?->실사용은 아니고 인자값이라 괜찮다.
	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerSuccess() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerFail() = 0;
};
