// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentBase.h"

// Sets default values
AEquipmentBase::AEquipmentBase()
{
	//EquipmentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EquipmentMesh"));
	//SetRootComponent(EquipmentMesh);
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// creating the timeline
	ChargeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("ChargeTimeline"));
	// creating some default values, can be over written in editor
	ChargeMax = 1;
	ChargeRate = 15;
	ChargeRequired = .5;

}

void AEquipmentBase::ChargeTimelineProgress(float progress)
{
	Charge = progress;
}

void AEquipmentBase::ChargeTimelineEnd()
{

}

void AEquipmentBase::ChargeUpdate(float ChargeChange)
{
	ChargeTimeline->SetNewTime(Charge - ChargeChange);
	ChargeTimeline->Play();
}

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

void AEquipmentBase::ChargeRateUpdate(float ChargeRateNew)
{
	ChargeRate = ChargeRateNew;
	ChargeTimeline->SetPlayRate(1 / ChargeRate);
}

void AEquipmentBase::ActivateEquipment()
{

}

// Called when the game starts or when spawned
void AEquipmentBase::BeginPlay()
{
	Super::BeginPlay();
	Charge = ChargeMax;
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

