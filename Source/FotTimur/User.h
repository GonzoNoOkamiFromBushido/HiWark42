// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "User.generated.h"

UCLASS()
class FOTTIMUR_API AUser : public APawn
{
	GENERATED_BODY()

public:
	AUser();
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* Body;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Move params")
		float speed = 1;

	void MoveForward(float AxisValue);
	void RotateRight(float AxisValue);
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	float CurrentMoveForward;
	float CurrentRotRight;

};
