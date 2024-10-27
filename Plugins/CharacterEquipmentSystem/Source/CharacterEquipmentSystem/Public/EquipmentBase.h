// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/TimelineComponent.h>
#include "GameFramework/Actor.h"
#include "EquipmentBase.generated.h"

UCLASS()
class CHARACTEREQUIPMENTSYSTEM_API AEquipmentBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEquipmentBase();

#pragma region TimelineFunctions
	//Timeline related functions, for the management of the equipment's usage and resource generation
	UFUNCTION(BlueprintCallable, Category = Charge)
	virtual void ChargeTimelineProgress(float progress);

	UFUNCTION(BlueprintCallable, Category = Charge)
	virtual void ChargeTimelineEnd();

	UFUNCTION(BlueprintCallable, Category = Charge)
	void ChargeUpdate(float ChargeChange);

	UFUNCTION(BlueprintCallable, Category = Charge)
	bool CanUseEquipment();

	UFUNCTION(BlueprintCallable, Category = Charge)
	void ChargeRateUpdate(float ChargeRateNew);
#pragma endregion

	//Function that handles the primary logic of the equipment, what it does when used.
	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	virtual void ActivateEquipment();

	//A float curve for the timeline to run on
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	UCurveFloat* ChargeTimelineCurve;

	//The timeline itself, responsible for managing the equipment's charge aka usability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	UTimelineComponent* ChargeTimeline;

	//The value that represents how much resource the equipment currently has to be able to use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float Charge;

	//The rate at which the charge resource replenishes when not in use. If you want to use item stocks instead of a cooldown system, set this number to 0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeRate;

	//The minimum use cost of the equipment, will also reduce current charge by this ammount on successful use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeRequired;

	//The maximum ammount of charge/ charges the equipment can have stocked at once
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeMax;

	//A bool that can be used to check if the equipment is currently usable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	bool CanDeploy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
