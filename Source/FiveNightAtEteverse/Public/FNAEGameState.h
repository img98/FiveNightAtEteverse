// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FNAEGameState.generated.h"

/**
 * 
 */
UCLASS()
class FIVENIGHTATETEVERSE_API AFNAEGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	bool GetIsPlayerHide();
	UFUNCTION(BlueprintCallable)
	void SetIsPlayerHide(bool InBool);
	UFUNCTION(BlueprintCallable)
	bool GetIsDoorLocked();
	UFUNCTION(BlueprintCallable)
	void SetIsDoorLocked(bool InBool);


protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	bool IsPlayerHide = 0;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	bool IsDoorLocked = 0;
};
