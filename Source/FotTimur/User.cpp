
#include "User.h"
#include "Kismet/KismetStringLibrary.h"

AUser::AUser()
{

	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene root component"));
	RootComponent = SceneComp;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body mesh"));
	Body->SetupAttachment(SceneComp);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArm->SetupAttachment(Body);
	SpringArm->bDoCollisionTest = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

void AUser::MoveForward(float AxisValue)
{
	CurrentMoveForward = AxisValue;
}

void AUser::RotateRight(float AxisValue)
{
	CurrentRotRight = AxisValue;
}

void AUser::RotateUp(float AxisValue)
{
	CurrentRotUp = AxisValue;
}

void AUser::BeginPlay()
{
	Super::BeginPlay();
}

void AUser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector OldPos = Body->GetComponentLocation();
	FVector NextPos = OldPos + Body->GetForwardVector() * speed * CurrentMoveForward;
	Body->SetWorldLocation(NextPos);

	FRotator OldRot = SpringArm->GetComponentRotation();
	float RotY = OldRot.Pitch + RotSpeed * CurrentRotUp;
	SpringArm->SetWorldRotation(FRotator(RotY, OldRot.Yaw, OldRot.Roll));

	FRotator OldRotForBody = Body->GetComponentRotation();
	float RotZforBody = OldRotForBody.Yaw + RotSpeed * CurrentRotRight;
	Body->SetRelativeRotation(FRotator(OldRotForBody.Pitch, RotZforBody, OldRotForBody.Roll));
}

void AUser::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

