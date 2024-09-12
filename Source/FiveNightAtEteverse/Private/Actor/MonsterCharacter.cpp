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
	GetWorldTimerManager().SetTimer(THUpdateAITick, this, &AMonsterCharacter::UpdateAITick, 0.01f, true); //SetTimerByFunctionName이 없어 delegate없이 타이머 돌리는 방법을 찾아봤다.
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

bool AMonsterCharacter::CheckPlayerStateSafe() //AnchorLocation에 도달하면 이함수 호출해서 체크
{
	//자식 클래스에서 각자의 체크로직 구현
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
	//강사님도 State바꾸는 작업은 하드코딩으로 하더라(AIBattleSystemCharacter.cpp).
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
	//TODO: 게임오버시키는 코드
}

void AMonsterCharacter::FindPlayerFail()
{
	//TODO: Monster를 비활성화시키는 코드.
}
