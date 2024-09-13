// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SecurityDoor.h"
#include "FNAEGameState.h"

// Sets default values
ASecurityDoor::ASecurityDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot=CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameStaticMesh"));
	DoorFrame->SetupAttachment(DefaultSceneRoot);
	DoorWindow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SlidingDoorStaticMesh"));
	DoorWindow->SetupAttachment(DoorFrame);
	OpenLocation = CreateDefaultSubobject<USceneComponent>(TEXT("OpenLocationSceneRoot"));
	OpenLocation->SetupAttachment(DoorFrame);
	CloseLocation = CreateDefaultSubobject<USceneComponent>(TEXT("CloseLocationSceneRoot"));
	CloseLocation->SetupAttachment(DoorFrame);

	DoorWindow->SetRelativeLocation(FVector(-100.f, 0.f, 0.f));
	OpenLocation->SetRelativeLocation(FVector(-100.f, 0.f, 0.f));
}

// Called when the game starts or when spawned
void ASecurityDoor::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());
	ensure(GameState);

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
	if (GetWorldTimerManager().IsTimerActive(THOpenMoving))
	{
		GetWorldTimerManager().ClearTimer(THOpenMoving);
	}

	GetWorld()->GetTimerManager().SetTimer(
		THCloseMoving,
		this,
		&ASecurityDoor::CloseMoving,
		0.01f,
		true	//bloop
	);
}

void ASecurityDoor::OpenDoor()
{
	GameState->SetIsDoorLocked(false);
	//TODO: 위치값 구해서 문짝 relativeLocation만 AddLocation해주자.
	if (GetWorldTimerManager().IsTimerActive(THCloseMoving))
	{
		GetWorldTimerManager().ClearTimer(THCloseMoving);
	}
	GetWorld()->GetTimerManager().SetTimer(
		THOpenMoving,
		this,
		&ASecurityDoor::OpenMoving,
		0.01f,
		true	//bloop
	);
}

void ASecurityDoor::SetOpenDoorTimer()
{
	if (!GetWorldTimerManager().IsTimerActive(THOpenDoor))
	{
		GetWorld()->GetTimerManager().SetTimer(
			THOpenDoor,
			this,
			&ASecurityDoor::OpenDoor,
			OpenInterval,
			false	//bloop
		);
	}
}

void ASecurityDoor::CloseMoving()
{	
	if (DoorWindow->GetRelativeLocation().X < CloseLocation->GetRelativeLocation().X)
	{
		FVector MoveDirection = CloseLocation->GetRelativeLocation() - DoorWindow->GetRelativeLocation();
		DoorWindow->AddRelativeLocation(MoveDirection.GetSafeNormal());
	}
	else
	{
		GetWorldTimerManager().ClearTimer(THCloseMoving);
	}
}

void ASecurityDoor::OpenMoving()
{
	if (DoorWindow->GetRelativeLocation().X > OpenLocation->GetRelativeLocation().X)
	{
		FVector MoveDirection = OpenLocation->GetRelativeLocation() - DoorWindow->GetRelativeLocation();
		DoorWindow->AddRelativeLocation(MoveDirection.GetSafeNormal());		
	}
	else
	{
		GetWorldTimerManager().ClearTimer(THOpenMoving);
	}
}

