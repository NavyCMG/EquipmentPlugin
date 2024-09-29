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

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = EquipmentFunctions)
	void ActivateEquipment();*/

	UFUNCTION(BlueprintCallable)
	virtual void UseEquipment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	UCurveFloat* ChargeTimelineCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	UTimelineComponent* ChargeTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float Charge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeRequired;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Charge)
	float ChargeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	bool CanDeploy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	UStaticMeshComponent* EquipmentMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
