// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/MonsterInterface.h"
#include "Enum/MonsterState.h"
#include "MonsterCharacter.generated.h"

class AFNAEGameState;

UCLASS()
class FIVENIGHTATETEVERSE_API AMonsterCharacter : public ACharacter, public IMonsterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<AFNAEGameState> GameState;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Default")
	EMonsterState CurrentState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual void CheckPlayerState();

};
