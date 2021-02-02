// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CPP_BasicCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CPP_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class THELOSTVILLAGE_API ACPP_PlayerCharacter : public ACPP_BasicCharacter
{
	GENERATED_BODY()

public:

	ACPP_PlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* Camera;

private:



protected:


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



public:

	
	
};
