// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HideSpot.h"
#include "Components/BoxComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
AHideSpot::AHideSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	HideCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HideCollisionBox"));
	HideCollision->SetupAttachment(DefaultSceneRoot);

	CabinetBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CabinetBoxStaticMesh"));
	CabinetBox->SetupAttachment(HideCollision);
	CabinetDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CabinetDoorStaticMesh"));
	CabinetDoor->SetupAttachment(CabinetBox);
	CabinetOuterHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CabinetOuterHandleStaticMesh"));
	CabinetOuterHandle->SetupAttachment(CabinetDoor);
	CabinetInnerHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CabinetInnerHandleleStaticMesh"));
	CabinetInnerHandle->SetupAttachment(CabinetDoor);

	OuterLeftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OuterLeftHandStaticMesh"));
	OuterLeftHand->SetupAttachment(CabinetOuterHandle);
	OuterRightHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OuterRightHandStaticMesh"));
	OuterRightHand->SetupAttachment(CabinetOuterHandle);
	InnerLeftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InnerLeftHandStaticMesh"));
	InnerLeftHand->SetupAttachment(CabinetInnerHandle);
	InnerRightHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InnerRightHandStaticMesh"));
	InnerRightHand->SetupAttachment(CabinetInnerHandle);
	
	Sign1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sign1StaticMesh"));
	Sign1->SetupAttachment(CabinetDoor);
	Sign2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sign2StaticMesh"));
	Sign2->SetupAttachment(CabinetDoor);
	Sign3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sign3StaticMesh"));
	Sign3->SetupAttachment(CabinetDoor);

	CabinetDoor->SetSimulatePhysics(true);
	
	OuterLeftHand->SetVisibility(false);
	OuterRightHand->SetVisibility(false);
	InnerLeftHand->SetVisibility(false);
	InnerRightHand->SetVisibility(false);

	HideCollision->OnComponentBeginOverlap.AddDynamic(this, &AHideSpot::BeginOverlap);
	HideCollision->OnComponentEndOverlap.AddDynamic(this, &AHideSpot::EndOverlap);
}

// Called when the game starts or when spawned
void AHideSpot::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AHideSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHideSpot::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AHideSpot::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

