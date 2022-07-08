// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "User.h"
#include "UserController.generated.h"


UCLASS()
class FOTTIMUR_API AUserController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
		AUser* User;
	void MoveForward(float AxisValue);
	void RotateRigt(float AxisValue);
	void RotateUp(float AxisValue);
};
