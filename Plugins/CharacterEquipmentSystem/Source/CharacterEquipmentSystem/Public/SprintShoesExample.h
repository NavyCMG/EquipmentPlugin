// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipmentBase.h"
#include "SprintShoesExample.generated.h"


class ACharacter;

UCLASS()
class CHARACTEREQUIPMENTSYSTEM_API ASprintShoesExample : public AEquipmentBase
{
	GENERATED_BODY()

	ASprintShoesExample();

	virtual void BeginPlay() override;
	
	virtual void ActivateEquipment();

	virtual void ChargeTimelineEnd();

	virtual void ChargeTimelineProgress(float progress);

	UPROPERTY()
	bool IsActive;

	UPROPERTY()
	ACharacter* OwningCharacter;
};
