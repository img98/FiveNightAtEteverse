// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCTVCam.generated.h"

class USceneCaptureComponent2D;

/** Please add a class description */
UCLASS()
class ACCTVCam : public AActor
{
	GENERATED_BODY()

public:
	ACCTVCam();

protected:
	virtual void BeginPlay() override;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> CameraMesh;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneCaptureComponent2D> SceneCaptureComponent;
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Default")
	TObjectPtr<UTextureRenderTarget2D> TextureTarget; //인스턴스에서 설정

public:
	virtual void Tick(float DeltaTime) override;
};
