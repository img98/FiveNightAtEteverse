// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/MonsterCharacter.h"
#include "Interface/MonsterInterface.h"
#include "HideMonster.generated.h"

/**
 * 
 */
UCLASS()
class FIVENIGHTATETEVERSE_API AHideMonster : public AMonsterCharacter
{
	GENERATED_BODY()
	
public:

protected:
	virtual	bool CheckPlayerStateSafe() override;

};
