// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CCTVMonitor.h"

// Sets default values
ACCTVMonitor::ACCTVMonitor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	MonitorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MonitorStaticMesh"));
	MonitorMesh->SetupAttachment(DefaultSceneRoot);
	Screen1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScreenStaticMesh"));
	Screen1->SetupAttachment(MonitorMesh);

}

// Called when the game starts or when spawned
void ACCTVMonitor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACCTVMonitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

