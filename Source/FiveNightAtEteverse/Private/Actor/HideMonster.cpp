// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HideMonster.h"
#include "FNAEGameState.h"

bool AHideMonster::CheckPlayerStateSafe()
{
	//플레이어가 캐비넷에 숨었는지 GameState를 통해 확인
	if (GameState->GetIsPlayerHide())
	{
		UE_LOG(LogTemp, Log, TEXT("Hiding"));
		return true;		
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Player is not Hiding"));
		return false;
	}
}
