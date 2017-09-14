// Fill out your copyright notice in the Description page of Project Settings.
// BuidlingEscape_01
#include "BuildingEscape_01.h"
#include "OpenDoor.h"

#define OUT

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

	// ...
	Owner = GetOwner();
	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngel, 0.f));
}



void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (GetTotalMassOfActosrOnPlatee() > 20.f)
	{
		// Open the Door
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (DoorCloseDelay + LastDoorOpenTime < GetWorld()->GetTimeSeconds())
	{
		CloseDoor();
	}
}

float UOpenDoor::GetTotalMassOfActosrOnPlatee()
{
	float TotalMass = 0.0f;

	// find all the overlapping Actors
	TArray<AActor*> OverLappingActorss;
	PresurePlate->GetOverlappingActors(OUT OverLappingActorss);
	for (const auto& Actor : OverLappingActorss)
	{
		// finde TotalMass
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}
	// Iterate through them adding their masses

	TArray<int32> T;
	T.Add(5);

	return TotalMass;
}