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
	float OpenInterval = 2.f;	//BP나 인스턴스에서 설정. 나중에 10초 정도로 늘려놓자.

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
