// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCTVMonitor.generated.h"

UCLASS()
class FIVENIGHTATETEVERSE_API ACCTVMonitor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACCTVMonitor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> MonitorMesh;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> Screen1; //��ũ�� �߰��� BP���� �ϱ�, mesh������ bp���� plane���� �ϱ�


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
