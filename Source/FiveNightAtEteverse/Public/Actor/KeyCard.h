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

	//GrabComponent는 언리얼사에서 BP로 만든 SceneComponent라 C++클래스가 없어 BP에서 추가하자.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> KeyCardMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
