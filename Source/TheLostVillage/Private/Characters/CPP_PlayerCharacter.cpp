// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CPP_PlayerCharacter.h"

ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = false;
	SpringArm->SetRelativeRotation(FRotator(300.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 800.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}



void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}