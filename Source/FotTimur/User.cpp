
#include "User.h"

AUser::AUser()
{

	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene root component"));
	RootComponent = SceneComp;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body mesh"));
	Body->SetupAttachment(SceneComp);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArm->SetupAttachment(Body);

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

void AUser::BeginPlay()
{
	Super::BeginPlay();
}

void AUser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector OldPos = Body->GetComponentLocation();
	FVector FNextPos = OldPos + Body->GetForwardVector() * speed * CurrentMoveForward;
	Body->SetWorldLocation(FNextPos);
}

void AUser::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

