// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/DoorMonster.h"
#include "FNAEGameState.h"

bool ADoorMonster::CheckPlayerStateSafe()
{
	if (GameState->GetIsDoorLocked())
	{
		return true;
	}
	else
	{
		return false;
	}
}

