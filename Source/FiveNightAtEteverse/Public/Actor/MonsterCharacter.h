// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/MonsterInterface.h"
#include "Enum/MonsterState.h"
#include "MonsterCharacter.generated.h"

class AFNAEGameState;
class AMonsterAIController;
class UBlackboardComponent;

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
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<AMonsterAIController> MonsterController;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UBlackboardComponent> Blackboard;
	UPROPERTY(BlueprintReadOnly, Category = "Default", Meta = (ExposeOnSpawn = true))
	TObjectPtr<AActor> Destination; //MonsterSpawner의 Destination을 할당

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UAnimMontage> FindSuccessMontage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	FTimerHandle THDoJumpscare;

	virtual void PossessedBy(AController* NewController) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual bool CheckPlayerStateSafe();

	UFUNCTION(BlueprintCallable)
	virtual void SetCurrentState(EMonsterState InState);

	UFUNCTION(BlueprintCallable)
	void SetDestination();

	UFUNCTION(BlueprintCallable)
	virtual void UpdateAITick();

	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerSuccess();

	UFUNCTION(BlueprintCallable)
	virtual void FindPlayerFail();
	UFUNCTION(BlueprintCallable)
	virtual void DoJumpscare();
};
