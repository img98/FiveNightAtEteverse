// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HideMonster.h"
#include "FNAEGameState.h"

bool AHideMonster::CheckPlayerStateSafe()
{
	//�÷��̾ ĳ��ݿ� �������� GameState�� ���� Ȯ��
	if (GameState->GetIsPlayerHide())
	{
		return true;		
	}
	else
	{
		return false;
	}
}
