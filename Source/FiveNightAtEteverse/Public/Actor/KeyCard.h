// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCard.generated.h"

UCLASS()
class FIVENIGHTATETEVERSE_API AKeyCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//GrabComponent�� �𸮾�翡�� BP�� ���� SceneComponent�� C++Ŭ������ ���� BP���� �߰�����.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> KeyCardMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
