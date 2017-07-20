// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelBasedAdventure.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	// ...
	FRotator NewDoorRotation = FRotator(0.0f, 75.0f, 0.0f);
	Owner->SetActorRotation(NewDoorRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//if actor that opens is in the volume
		UOpenDoor::OpenDoor();
	}
}

