// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "CPP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THELOSTVILLAGE_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	
		

private:

	bool bLMBPressed;

	FHitResult HitResultUnderCursor;

	FVector ResultLocation;

	FTimerHandle StopMovementTimer;

public:

	ACPP_PlayerController();
	
private:
		
	void LeftMouseButtonPressed();
	
	void LeftMouseButtonReleased();

	void StopMovementTimerExpired();

	UFUNCTION(Server, Reliable)
	void MoveToLocationOnServer(AController* Controller, FVector Goal);

	UFUNCTION(Server, Reliable)
	void StopMovementOnServer(AController* Controller);

protected:

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float DeltaTime) override;
	
};
