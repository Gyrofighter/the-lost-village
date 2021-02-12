// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/CPP_PlayerController.h"


ACPP_PlayerController::ACPP_PlayerController()
{
	bShowMouseCursor = true;
	bLMBPressed = false;

}




void ACPP_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (GetPawn() && bLMBPressed && GetHitResultUnderCursor(ECC_Visibility, false, HitResultUnderCursor))
	{
		ResultLocation = HitResultUnderCursor.Location;
		GetPawn()->AddMovementInput(UKismetMathLibrary::GetDirectionUnitVector(GetPawn()->GetActorLocation(), ResultLocation));
	}	
}


void ACPP_PlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
	InputComponent->BindAction("LMBClick", IE_Pressed, this, &ACPP_PlayerController::LeftMouseButtonPressed);
	InputComponent->BindAction("LMBClick", IE_Released, this, &ACPP_PlayerController::LeftMouseButtonReleased);
	

}

void ACPP_PlayerController::LeftMouseButtonPressed()
{
	bLMBPressed = true;
	GetWorld()->GetTimerManager().SetTimer(StopMovementTimer, this, &ACPP_PlayerController::StopMovementTimerExpired, 0.1f, false);
}

void ACPP_PlayerController::LeftMouseButtonReleased()
{
	bLMBPressed = false;
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, ResultLocation);
	MoveToLocationOnServer(this, ResultLocation);
	GetWorld()->GetTimerManager().PauseTimer(StopMovementTimer);
	
	
}

void ACPP_PlayerController::StopMovementTimerExpired()
{

	StopMovement();
	StopMovementOnServer(this);

}

void ACPP_PlayerController::StopMovementOnServer_Implementation(AController* Controller)
{

	Controller->StopMovement();
}

void ACPP_PlayerController::MoveToLocationOnServer_Implementation(AController* Controller, FVector Goal)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal);
}
