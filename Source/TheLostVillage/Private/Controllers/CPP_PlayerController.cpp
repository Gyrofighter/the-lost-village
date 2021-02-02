// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/CPP_PlayerController.h"


ACPP_PlayerController::ACPP_PlayerController()
{
	bShowMouseCursor = true;
	bLeftMouseInputPressed = false;

}


void ACPP_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bLeftMouseInputPressed)
	{
		FHitResult L_Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, L_Hit);
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, L_Hit.Location);		
	}
}



void ACPP_PlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseInput", IE_Pressed, this, &ACPP_PlayerController::LeftMouseInputPressed);
	InputComponent->BindAction("LeftMouseInput", IE_Released, this, &ACPP_PlayerController::LeftMouseInputReleased);

}

void ACPP_PlayerController::LeftMouseInputPressed()
{
	bLeftMouseInputPressed = true;
}

void ACPP_PlayerController::LeftMouseInputReleased()
{
	bLeftMouseInputPressed = false;
}