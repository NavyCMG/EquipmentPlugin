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


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTEREQUIPMENTSYSTEM_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

	UPROPERTY()
	APawn* Owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	UInputMappingContext* EquipmentMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	UInputAction* UseEquipmentAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AEquipmentBase* CurrentEquipment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	TSubclassOf<AEquipmentBase> StartingEquipment;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AActor* CurrentEquipmentIDK;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	TArray <TSubclassOf<AEquipmentBase>> EquipmentAvailable;

	UFUNCTION(BlueprintCallable, Category = EquipmentComponent)
	void UseEquipment();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
