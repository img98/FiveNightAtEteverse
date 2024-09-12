// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SecurityDoor.h"
#include "FNAEGameState.h"

// Sets default values
ASecurityDoor::ASecurityDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASecurityDoor::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());
	
}

// Called every frame
void ASecurityDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecurityDoor::CloseDoor()
{
	GameState->SetIsDoorLocked(true);

	if (GetWorldTimerManager().IsTimerActive(THOpenDoor))
	{
		GetWorldTimerManager().ClearTimer(THOpenDoor);
	}

	//TODO: 위치값 구해서 문짝 relativeLocation만 AddLocation해주자.
}

void ASecurityDoor::OpenDoor()
{
	GameState->SetIsDoorLocked(true);
	//TODO: 위치값 구해서 문짝 relativeLocation만 AddLocation해주자.
}

void ASecurityDoor::SetOpenDoorTimer()
{
	GetWorld()->GetTimerManager().SetTimer(
		THOpenDoor,
		this,
		&ASecurityDoor::OpenDoor,
		OpenInterval,
		false	//bloop
	);
}

