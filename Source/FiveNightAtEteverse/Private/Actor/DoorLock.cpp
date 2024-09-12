// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/DoorLock.h"
#include "Components/BoxComponent.h"
#include "Actor/SecurityDoor.h"
#include "Actor/KeyCard.h"

// Sets default values
ADoorLock::ADoorLock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	BoxCollision->SetupAttachment(DefaultSceneRoot);
	DoorLock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLockStaticMesh"));
	DoorLock->SetupAttachment(BoxCollision);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADoorLock::BeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ADoorLock::EndOverlap);
}

// Called when the game starts or when spawned
void ADoorLock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorLock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorLock::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AKeyCard>(OtherActor) == KeyCard)
	{
		SecurityDoor->CloseDoor();
	}
}

void ADoorLock::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	SecurityDoor->SetOpenDoorTimer();
}

