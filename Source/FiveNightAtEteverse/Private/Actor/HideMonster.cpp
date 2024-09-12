// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HideMonster.h"
#include "FNAEGameState.h"

bool AHideMonster::CheckPlayerStateSafe()
{
	//�÷��̾ ĳ��ݿ� �������� GameState�� ���� Ȯ��
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
