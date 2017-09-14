// Fill out your copyright notice in the Description page of Project Settings.
// BuidlingEscape_01
#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Gameframework/Actor.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_01_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CloseDoor();
	void OpenDoor();
private:

	UPROPERTY(VisibleAnyWhere)
		float OpenAngel = -90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PresurePlate;
	
	float DoorCloseDelay = 1.f;
	float LastDoorOpenTime;

	//AActor* ActorThatOpens;
	AActor* Owner;

	// Returns Total Mass in kg
	float GetTotalMassOfActosrOnPlatee();
};