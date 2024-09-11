// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HideMonster.h"
#include "FNAEGameState.h"

void AHideMonster::CheckPlayerState()
{
	//�÷��̾ ĳ��ݿ� �������� GameState�� ���� Ȯ��
	if (GameState->GetIsPlayerHide())
	{
		UE_LOG(LogTemp, Log, TEXT("Player is not Hiding"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Hiding"));
	}
}
