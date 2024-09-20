// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MonsterCharacter.h"
#include "FNAEGameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AI/MonsterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMonsterCharacter::AMonsterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AMonsterCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);


	//�����ʸ� ����ϱ⿡ beginPlay�ڵ带 Possess�ɶ��� �Ű��.
	GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());

	MonsterController = Cast<AMonsterAIController>(GetController());
	ensure(MonsterController);
	Blackboard = MonsterController->GetBlackboardComponent();
	ensure(Blackboard);

	SetCurrentState(EMonsterState::Move); //�Ŀ� ��Ī�Ҷ��� Idle�� �����ϰ� ����. Idle���� Ư�� Ʈ���ŷ� Move�� �ǰ� �ٲ۴�.
	SetDestination();

	FTimerHandle THUpdateAITick;
	GetWorldTimerManager().SetTimer(THUpdateAITick, this, &AMonsterCharacter::UpdateAITick, 0.01f, true); //SetTimerByFunctionName�� ���� delegate���� Ÿ�̸� ������ ����� ã�ƺô�.
}

// Called every frame
void AMonsterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AMonsterCharacter::CheckPlayerStateSafe() //AnchorLocation�� �����ϸ� ���Լ� ȣ���ؼ� üũ
{
	//�ڽ� Ŭ�������� ������ üũ���� ����
	UE_LOG(LogTemp, Warning, TEXT("Make CheckPlayerStateSafe At ChildClass"));
	return false;
}

void AMonsterCharacter::SetCurrentState(EMonsterState InState)
{
	CurrentState = InState;
	check(Blackboard);
	Blackboard->SetValueAsEnum("AIState", (uint8)InState);
}

void AMonsterCharacter::SetDestination()
{
	ensure(Destination);
	Blackboard->SetValueAsObject("Destination", Destination);
}

void AMonsterCharacter::UpdateAITick()
{
	//����Ե� State�ٲٴ� �۾��� �ϵ��ڵ����� �ϴ���(AIBattleSystemCharacter.cpp).
	//������ AIState�� ������ BT������ �ٷ�ڴ�.
	SetCurrentState((EMonsterState)Blackboard->GetValueAsEnum("AIState"));
	switch(CurrentState)
	{
	case EMonsterState::Idle:

		break;
	case EMonsterState::Move:

		break;
	case EMonsterState::Check:

		break;
	case EMonsterState::Find:

		break;
	case EMonsterState::NotFind:

		break;
	default:
		break;
	}
}

void AMonsterCharacter::FindPlayerSuccess()
{
	if (!GetWorldTimerManager().IsTimerActive(THDoJumpscare))
		GetWorldTimerManager().SetTimer(
			THDoJumpscare,
			this,
			&AMonsterCharacter::DoJumpscare, //�����Լ��̱⿡ AMonsterCharacter:: ������ �ڽ��Լ��� ���ü� �ִ�.
			2.f,
			false	//bloop
		);
}

void AMonsterCharacter::FindPlayerFail()
{
	//TODO: Monster�� ��Ȱ��ȭ��Ű�� �ڵ�.
}

void AMonsterCharacter::DoJumpscare()
{
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	FVector SpawnDistance = CameraManager->GetActorForwardVector() * 225.f;
	FVector SpawnLocation = CameraManager->GetCameraLocation() + SpawnDistance;
	SetActorLocation(SpawnLocation);

	FRotator LookAtRotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), CameraManager->GetCameraLocation());
	SetActorRotation(LookAtRotator);

	if (FindSuccessMontage)
	{
		PlayAnimMontage(FindSuccessMontage);
	}

	UE_LOG(LogTemp, Warning, TEXT("called by AMonsterCharacter"));
	//TODO: �������� �ٳ����� ���ӿ��� ����ϴ� ��� ã�ƺ���. AnimMontage������ Notify�� �ᵵ ���� �� ����.
}
