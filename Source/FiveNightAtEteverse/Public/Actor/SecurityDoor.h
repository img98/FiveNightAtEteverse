// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecurityDoor.generated.h"

class AFNAEGameState;

UCLASS()
class FIVENIGHTATETEVERSE_API ASecurityDoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASecurityDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<AFNAEGameState> GameState;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	FTimerHandle THOpenDoor;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	float OpenInterval = 2.f;	//BP�� �ν��Ͻ����� ����. ���߿� 10�� ������ �÷�����.

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CloseDoor();
	UFUNCTION(BlueprintCallable)
	void OpenDoor();
	UFUNCTION(BlueprintCallable)
	void SetOpenDoorTimer();
};
