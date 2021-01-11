// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CPP_BasicCharacter.h"

// Sets default values
ACPP_BasicCharacter::ACPP_BasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_BasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_BasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

