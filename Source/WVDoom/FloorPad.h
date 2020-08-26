// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "iInteract.h"

#include "FloorPad.generated.h"

class UBoxComponent;

UCLASS()
class WVDOOM_API AFloorPad : public AActor, public IiInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	USceneComponent* FloorPadRoot;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* FloorPadMesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* FloorPadBox;

	void OnInteract(AActor* PlayerActor);

};
