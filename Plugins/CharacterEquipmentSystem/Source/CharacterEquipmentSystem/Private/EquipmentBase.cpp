// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentBase.h"

// Sets default values
AEquipmentBase::AEquipmentBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// creating the timeline
	ChargeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("ChargeTimeline"));
	// creating some default values, can be over written in editor
	ChargeMax = 1;
	ChargeRate = 5;
	ChargeRequired = .5;
}

//Function responsible for using the timeline to update the Charge value
void AEquipmentBase::ChargeTimelineProgress(float progress)
{
	Charge = progress;
}

//A function to be used upon timeline end (when at full charge). Currently doesn't do anything, feel free to set any personal functions here or overwrite in blueprint
void AEquipmentBase::ChargeTimelineEnd()
{

}

//A function for communicating a change in the current charge ammount to the timeline
void AEquipmentBase::ChargeUpdate(float ChargeChange)
{
	ChargeTimeline->SetNewTime(Charge - ChargeChange);
	ChargeTimeline->Play();
}

//A function for checking if the equipment is currently usable
bool AEquipmentBase::CanUseEquipment()
{
	if (Charge >= ChargeRequired)
	{
		CanDeploy = true;
	}
	else
	{
		CanDeploy = false;
	}
	return CanDeploy;
}

//Allows for changing the speed that the equipment recharges at in secconds
void AEquipmentBase::ChargeRateUpdate(float ChargeRateNew)
{
	ChargeRate = ChargeRateNew;
	ChargeTimeline->SetPlayRate(1 / ChargeRate);
}

//Performs whatever the equipment's unique function is and reduces charge by the appropriate ammount
void AEquipmentBase::ActivateEquipment()
{
	if (CanUseEquipment())
	{
		Charge -= ChargeRequired;
		//message to visually show that this function was called properly
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Activate equipment from equipment base"));
	}
}

// Called when the game starts or when spawned
void AEquipmentBase::BeginPlay()
{
	Super::BeginPlay();
	Charge = ChargeMax;
	//Sets the timeline to match the current charge
	ChargeTimeline->SetPlaybackPosition((Charge / ChargeMax), false, false);
	ChargeRateUpdate(ChargeRate);

	//create and bind an event/ function to the timeline start
	FOnTimelineFloat ProgressUpdate;
	ProgressUpdate.BindUFunction(this, FName("ChargeTimelineProgress"));

	ChargeTimeline->AddInterpFloat(ChargeTimelineCurve, ProgressUpdate); //Ties Timeline float to normal float

	//create and bind an event/ function to the timeline ending
	FOnTimelineEvent ChargeEnd;
	ChargeEnd.BindUFunction(this, FName("ChargeTimelineEnd"));
	ChargeTimeline->SetTimelineFinishedFunc(ChargeEnd);
	
}

// Called every frame
void AEquipmentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

