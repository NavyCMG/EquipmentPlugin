// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <EquipmentBase.h>
#include "CharacterEquipmentComponent.generated.h"

class UInputAction;
struct FInputActionValue;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTEREQUIPMENTSYSTEM_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	//UCurveFloat* ChargeTimelineCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AEquipmentBase* CurrentEquipment;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AActor* CurrentEquipmentIDK;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	TArray <AEquipmentBase*> EquipmentAvailable;

	UFUNCTION(BlueprintCallable, Category = EquipmentComponent)
	void UseEquipment();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
