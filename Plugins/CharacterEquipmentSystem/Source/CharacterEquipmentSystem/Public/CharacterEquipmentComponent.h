// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <EquipmentBase.h>
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "CharacterEquipmentComponent.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputLocalPlayerSubsystem;
class UEnhancedInputComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTEREQUIPMENTSYSTEM_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	//A variable to save the owning pawn of this instance of the equipment component
	UPROPERTY()
	APawn* Owner;

public:	
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

	//A new input mapping context to add inputs to the player without needing to modify or code the player's existing input
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	UInputMappingContext* EquipmentMappingContext;

	//An input action to bind to the new input mapping context for the use of the equipment
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	UInputAction* UseEquipmentAction;

	//The current active equipment that all functionality would be called on
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AEquipmentBase* CurrentEquipment;

	//A reference to an equipment to spawn on begin play with this equipment, the spawned equipment becomes the Current equipment
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	TSubclassOf<AEquipmentBase> StartingEquipment;

	//Function to communicate with the Current equipment to call it's use function
	UFUNCTION(BlueprintCallable, Category = EquipmentComponent)
	void UseEquipment();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
