// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/MonsterCharacter.h"
#include "DoorMonster.generated.h"

/**
 * 
 */
UCLASS()
class FIVENIGHTATETEVERSE_API ADoorMonster : public AMonsterCharacter
{
	GENERATED_BODY()
	
public:
	virtual bool CheckPlayerStateSafe() override;
};
