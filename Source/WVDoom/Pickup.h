// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "iInteract.h"

#include "Pickup.generated.h"


class UBoxComponent;

UCLASS()
class WVDOOM_API APickup : public AActor, IiInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* PickupRoot;

	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* PickupBox;


};
