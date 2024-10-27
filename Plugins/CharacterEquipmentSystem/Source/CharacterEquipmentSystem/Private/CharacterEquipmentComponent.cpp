// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEquipmentComponent.h"


// Sets default values for this component's properties
UCharacterEquipmentComponent::UCharacterEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}

//Called from the Equipment component to use the functionality of the currently used equipment itself
void UCharacterEquipmentComponent::UseEquipment()
{
	CurrentEquipment->ActivateEquipment();	
	//on screen message for the purpose of validating the function is being called correctly
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("UseEquipment From component"));
}

// Called when the game starts
void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	//Set this component's owner as a variable
	Owner = Cast<APawn>(GetOwner());
	//If a starting equipment is selected, spawn an instance of said equipment for the player to use.
	if (StartingEquipment != nullptr)
	{
		CurrentEquipment = (AEquipmentBase*) GetWorld()->SpawnActor(StartingEquipment);
	}
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Owner->GetController()))
	{
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(EquipmentMappingContext, 3);
		}
		//Bind the equipment component function to the new input mapping context.
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			EnhancedInputComponent->BindAction(UseEquipmentAction, ETriggerEvent::Triggered, this, &UCharacterEquipmentComponent::UseEquipment);

		}
	}
}


// Called every frame
void UCharacterEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

