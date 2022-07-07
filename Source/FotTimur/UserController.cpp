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
	InputComponent->BindAxis("RotRight", this, &AUserController::RotateRigt);
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
