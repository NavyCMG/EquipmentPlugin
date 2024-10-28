// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintShoesExample.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


ASprintShoesExample::ASprintShoesExample()
{
	//sets default values
	ChargeRequired = 0;
	Charge = 1;
	IsActive = false;
}

void ASprintShoesExample::BeginPlay()
{
	Super::BeginPlay();
	//Get a reference to the character that owns this equipment
	OwningCharacter = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

//logic for when the equipment is used
void ASprintShoesExample::ActivateEquipment()
{
	//checks to see if equipment is being used and if it has enough charge to use
	if (IsActive == false && Charge > .1)
	{
		//starts draining the charge at a steady rate while speading up the player
		IsActive = true;
		ChargeTimeline->Reverse();
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= 2;
	}
	else
	{
		//deactivates the equipment early if it is already in use and sets the speed back to normal
		IsActive = false;
		ChargeTimeline->Play();
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= .5;
	}
}

//logic for when the timeline reaches the end of its playback
void ASprintShoesExample::ChargeTimelineEnd()
{
	Super::ChargeTimelineEnd();
	//checks to see if the timeline ended at max charge or not
	if (Charge < ChargeMax)
	{
		ChargeTimeline->Play();
	}
	//Auto deactivates the equipment if it runs out of charge
	if (IsActive == true)
	{
		IsActive = false;
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= .5;
	}
}

void ASprintShoesExample::ChargeTimelineProgress(float progress)
{
	Charge = progress;
	//debug only code to show current charge value due to lack of UI elements
	UE_LOG(LogTemp, Warning, TEXT("Charge: %.2f"), Charge);
}
