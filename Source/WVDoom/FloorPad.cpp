// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorPad.h"

#include "PlayerCharacter.h"

// Sets default values
AFloorPad::AFloorPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	FloorPadRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FloorPadRoot"));
	RootComponent = FloorPadRoot;
	//Comment
	
	FloorPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorPadMesh"));
	FloorPadMesh->AttachToComponent(FloorPadRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
}

// Called when the game starts or when spawned
void AFloorPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloorPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorPad::OnInteract(AActor* PlayerActor)
{

}

