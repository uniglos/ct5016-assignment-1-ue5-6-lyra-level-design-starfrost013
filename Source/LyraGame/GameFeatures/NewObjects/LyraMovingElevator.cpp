// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatures/NewObjects/LyraMovingElevator.h"

// Sets default values
ALyraMovingElevator::ALyraMovingElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
#
	box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	UStaticMesh* boxMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;

	this->SetRootComponent(box);

	// Don't div0 and die
	if (Speed == 0)
		Speed = 32;
}

// Called when the game starts or when spawned
void ALyraMovingElevator::BeginPlay()
{
	Super::BeginPlay();

	initialHeight = GetActorLocation().Y;

	finalHeight = initialHeight + HeightChange;
	stepHeight = HeightChange / Speed;
}

// Called every frame
void ALyraMovingElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto location = GetActorLocation();

	// todo: probably some epsilon stuff
	if (down)
	{
		location.Y -= stepHeight;
	
		if (location.Y <= initialHeight)
			down = false; 
	}
	else
	{
		location.Y += stepHeight;

		if (location.Y >= finalHeight)
			down = true; 
	}

	SetActorLocation(location);
}

