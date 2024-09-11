// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CCTVCam.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
ACCTVCam::ACCTVCam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	CameraMesh->SetupAttachment(DefaultSceneRoot);
	SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent2D"));
	SceneCaptureComponent->SetupAttachment(CameraMesh);
	
	SceneCaptureComponent->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
	SceneCaptureComponent->SetRelativeLocation(FVector(0.f, 14.f, 3.f));
	SceneCaptureComponent->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
		
}

// Called when the game starts or when spawned
void ACCTVCam::BeginPlay()
{
	Super::BeginPlay();
	SceneCaptureComponent->TextureTarget = TextureTarget;
}

// Called every frame
void ACCTVCam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

