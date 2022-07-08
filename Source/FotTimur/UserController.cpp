// Fill out your copyright notice in the Description page of Project Settings.


#include "UserController.h"

void AUserController::BeginPlay()
{
	Super::BeginPlay();
	User = Cast<AUser>(GetPawn());
}

void AUserController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AUserController::MoveForward);
	InputComponent->BindAxis("MouseX", this, &AUserController::RotateRigt);
	InputComponent->BindAxis("MouseY", this, &AUserController::RotateUp);
}

void AUserController::Tick(float DeltaTime)
{
}

void AUserController::MoveForward(float AxisValue)
{
	if (User)
		User->MoveForward(AxisValue);

}

void AUserController::RotateRigt(float AxisValue)
{
	if (User)
		User->RotateRight(AxisValue);
}

void AUserController::RotateUp(float AxisValue)
{
	if (User)
		User->RotateUp(AxisValue);
}
