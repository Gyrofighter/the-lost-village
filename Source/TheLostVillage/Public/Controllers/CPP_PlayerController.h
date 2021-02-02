// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "CPP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THELOSTVILLAGE_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ACPP_PlayerController();


private:

	bool bLeftMouseInputPressed;


private:

	void LeftMouseInputPressed();
	void LeftMouseInputReleased();


protected:


	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;
	
};
