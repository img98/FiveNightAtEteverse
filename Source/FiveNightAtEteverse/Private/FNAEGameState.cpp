// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAEGameState.h"

bool AFNAEGameState::GetIsPlayerHide()
{
	return IsPlayerHide;
}

void AFNAEGameState::SetIsPlayerHide(bool InBool)
{
	IsPlayerHide = InBool;
}