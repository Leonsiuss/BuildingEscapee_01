// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabberr.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_01_API UGrabberr : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberr();

	// Called when the game starts
	virtual void BeginPlay() override;


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	//
	float Reachh = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandlee = nullptr;
	UInputComponent* InputComponentt = nullptr;

	/// Ray-cast and Grab what's in reach
	void Grabb();

	///
	void Releasedd();

	/// Find attached physical handle
	void FindPhysicalHandelComponentt();

	/// Setup (assumed) attached input component
	void SetupInputComponentt();

	/// Return Hit for the first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReachh();

	// returns current start of reach line
	FVector GetReachLineStartt();

	// returns current end of reach line
	FVector GetReachLineEndd();
};