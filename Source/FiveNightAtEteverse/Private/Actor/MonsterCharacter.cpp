// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MonsterCharacter.h"
#include "FNAEGameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AI/MonsterAIController.h"

// Sets default values
AMonsterCharacter::AMonsterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());

	MonsterController = Cast<AMonsterAIController>(GetController());
	ensure(MonsterController);
	Blackboard = MonsterController->GetBlackboardComponent();
	ensure(Blackboard);

	SetCurrentState(EMonsterState::Move);
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
	SetCurrentState((EMonsterState)Blackboard->GetValueAsEnum("AIState"));
	switch(CurrentState)
	{
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
	//TODO: ���ӿ�����Ű�� �ڵ�
}

void AMonsterCharacter::FindPlayerFail()
{
	//TODO: Monster�� ��Ȱ��ȭ��Ű�� �ڵ�.
}
