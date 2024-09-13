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

	OuterHandleCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("OuterHandleCollisionBox"));
	OuterHandleCollision->SetupAttachment(CabinetOuterHandle);
	InnerHandleCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("InnerCollisionBox"));
	InnerHandleCollision->SetupAttachment(CabinetInnerHandle);

	OuterLeftHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OuterLeftHandSkeletalMesh"));
	OuterLeftHand->SetupAttachment(CabinetOuterHandle);
	OuterRightHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OuterRightHandSkeletalMesh"));
	OuterRightHand->SetupAttachment(CabinetOuterHandle);
	InnerLeftHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("InnerLeftHandSkeletalMesh"));
	InnerLeftHand->SetupAttachment(CabinetInnerHandle);
	InnerRightHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("InnerRightHandSkeletalMesh"));
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

	InnerHandleCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision); //HideCollision에 플레이어가 들어간다면 CollisionEnabled해주기

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

