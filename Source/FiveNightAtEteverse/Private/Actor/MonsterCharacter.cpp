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


	//스포너를 사용하기에 beginPlay코드를 Possess될때로 옮겼다.
	GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());

	MonsterController = Cast<AMonsterAIController>(GetController());
	ensure(MonsterController);
	Blackboard = MonsterController->GetBlackboardComponent();
	ensure(Blackboard);

	SetCurrentState(EMonsterState::Move); //후에 런칭할때는 Idle로 시작하게 하자. Idle에서 특정 트리거로 Move가 되게 바꾼다.
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
	//앞으로 AIState의 변경은 BT에서만 다루겠다.
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
			&AMonsterCharacter::DoJumpscare, //가상함수이기에 AMonsterCharacter:: 이지만 자식함수가 나올수 있다.
			2.f,
			false	//bloop
		);
}

void AMonsterCharacter::FindPlayerFail()
{
	//TODO: Monster를 비활성화시키는 코드.
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
	//TODO: 위내용이 다끝나면 게임오버 출력하는 방법 찾아보자. AnimMontage끝나는 Notify를 써도 좋을 것 같다.
}
