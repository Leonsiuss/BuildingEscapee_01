// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape_01.h"
#include "Grabberr.h"

#define OUT // remind me that vairabels will be changened

// Sets default values for this component's properties
UGrabberr::UGrabberr()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberr::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//UE_LOG(LogTemp, Warning, TEXT("Grabber Reporting For Duty!"));

	FindPhysicalHandelComponentt();

	SetupInputComponentt();
}

/// Look for attached input component (only appears at run time)
void UGrabberr::SetupInputComponentt()
{
	InputComponentt = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponentt)
	{
		/// Bind Input axis
		InputComponentt->BindAction("Grabb", IE_Pressed, this, &UGrabberr::Grabb); // qualify class name 1
		InputComponentt->BindAction("Grabb", IE_Released, this, &UGrabberr::Releasedd);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s - has not Component InputComponent..."), *GetOwner()->GetName())
	}
}



/// Look for attached physical handel
void UGrabberr::FindPhysicalHandelComponentt() // qualify class name = 1
{
	PhysicsHandlee = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>(); // GetComponentByClass<UPhysicsHandleComponent>() ar mushaobs Get ver agiqva Find-is nacvlad
	if (PhysicsHandlee == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s - has not Component PhysicsHandle..."), *GetOwner()->GetName())
	}
}

void UGrabberr::Grabb()
{

	/// LINE TRACE and see if we reach any actors with physics body collision channel set
	FHitResult HitResulttt  = GetFirstPhysicsBodyInReachh();
	auto ComponentToGrabb = HitResulttt.GetComponent(); // gets the mash in our case
	auto ActorHitt = HitResulttt.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHitt != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Line Trace: %s"), *ActorHitt->GetName())
        
		// attach physics handle
		PhysicsHandlee->GrabComponent(
			ComponentToGrabb,   // HitResultt change to GrabComponent  
			NAME_None,         // it's for bones name, now needn't
			ComponentToGrabb->GetOwner()->GetActorLocation(),  // allow us to Grab object at this Location
			true  // allow rotation
		);
	}
}

// Released igive qmedebaa rac Grabb magram mushaobs dayovnebit (rasac ganapirobebs IE_Released) Grabb-ze ertxel dacherit 
// amushavdeba Action magram sanum gilaks ar aushveb Released ar ganxorcieldeba (swored es aris Released danishnuleba)
void UGrabberr::Releasedd() 
{
		PhysicsHandlee->ReleaseComponent();
}


// Called every frame
void UGrabberr::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If the physics handle is attached
	if (PhysicsHandlee->GrabbedComponent)
	{

		// move the object that we are holding
		PhysicsHandlee->SetTargetLocation(GetReachLineEndd()); // allow us to set new Location in every frame
	}
}


const FHitResult UGrabberr::GetFirstPhysicsBodyInReachh()
{

	//FColor C(255, 0, 0);
	/*DrawDebugLine(           // funqcia romelic xatavs witel lazers DafaultPawn-s win vizualizaciistvis
	GetWorld(),
	PlayerViewPointLocationn,
	LineTraceEndd,
	FColor(255, 0, 0), // C
	false,
	0.f,
	0.f,
	10.f
	);*/

	/// Set up query parametrs
	/*const FName TraceTag("MyTraceTag");    // xatavs tetr da witel xazebs DebugDrawTraceTag
	GetWorld()->DebugDrawTraceTag = TraceTag;*/
	FCollisionQueryParams TraceParameterss(FName(TEXT("")), false, GetOwner()); // shesadzleblia mxolod TEXT("") aseti ganacadic nacvlad FName(TEXT(""))

	/// Line trace (AKA ray-cast) out to reach distance
	FHitResult HitResultt;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResultt,
		GetReachLineStartt(),
		GetReachLineEndd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameterss
	);

	return HitResultt;
}

FVector UGrabberr::GetReachLineStartt()
{
	/// Get Player View Point
	FVector PlayerViewPointLocationn;
	FRotator PlayerViewPointRotationn;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocationn,
		OUT PlayerViewPointRotationn
	);
	return PlayerViewPointLocationn;
}

FVector UGrabberr::GetReachLineEndd()
{
	/// Get Player View Point
	FVector PlayerViewPointLocationn;
	FRotator PlayerViewPointRotationn;

	/*AActor* Ownerr;            // esec dasashvebia qvemot mocemuli kodis nacvlad
	Ownerr = GetOwner();
	Ownerr->GetActorEyesViewPoint(
		OUT PlayerViewPointLocationn,
		OUT PlayerViewPointRotationn
	);*/

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocationn,
		OUT PlayerViewPointRotationn
	);
	return PlayerViewPointLocationn + PlayerViewPointRotationn.Vector() * Reachh;
}