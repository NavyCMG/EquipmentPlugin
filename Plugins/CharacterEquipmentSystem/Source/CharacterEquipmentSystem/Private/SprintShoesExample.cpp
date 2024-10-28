// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintShoesExample.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


ASprintShoesExample::ASprintShoesExample()
{
	ChargeRequired = 0;
	Charge = 1;
	IsActive = false;
}

void ASprintShoesExample::BeginPlay()
{
	Super::BeginPlay();
	//OwningCharacter = Cast<ACharacter>(GetOwner());
	//OwningCharacter->
	OwningCharacter = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ASprintShoesExample::ActivateEquipment()
{
	if (IsActive == false && Charge > .1)
	{
		IsActive = true;
		ChargeTimeline->Reverse();
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= 2;
		//UE_LOG(LogTemp, Warning, TEXT("Charge: %.2f"), Charge);
	}
	else
	{
		IsActive = false;
		ChargeTimeline->Play();
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= .5;
		//UE_LOG(LogTemp, Warning, TEXT("Charge: %.2f"), Charge);
	}
}

void ASprintShoesExample::ChargeTimelineEnd()
{
	Super::ChargeTimelineEnd();
	if (Charge < ChargeMax)
	{
		ChargeTimeline->Play();
	}
	if (IsActive == true)
	{
		IsActive = false;
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed *= .5;
	}
}

void ASprintShoesExample::ChargeTimelineProgress(float progress)
{
	Charge = progress;
	UE_LOG(LogTemp, Warning, TEXT("Charge: %.2f"), Charge);
}
