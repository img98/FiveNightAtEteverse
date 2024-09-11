// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyCharacter.h"
#include "FNAEGameState.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::CheckPlayerState() //AnchorLocation에 도달하면 이함수 호출해서 체크
{
	//일단 이런식으로 캐스트하고 기능수행한다는 예시. 후에 자식에서 쓸때는 없애자
	AFNAEGameState* GameState = Cast<AFNAEGameState>(GetWorld()->GetGameState());
	if (!GameState->GetIsPlayerHide())
	{
		UE_LOG(LogTemp, Log, TEXT("CheckPlayerState : Player is not Hiding"));
	}
}