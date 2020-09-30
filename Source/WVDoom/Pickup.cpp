// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Engine/World.h"



// Sets default values
APickup::APickup()
{

	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup::SendPickupToActor(AActor* PlayerActor)
{
	FVector actorLocation = PlayerActor->GetActorLocation();
	FVector pickupLocation = PickupMesh->GetComponentLocation();
	PickupMesh->SetWorldLocation(FMath::Lerp(PickupMesh->GetComponentLocation(), actorLocation, 0.01f));
	
}





