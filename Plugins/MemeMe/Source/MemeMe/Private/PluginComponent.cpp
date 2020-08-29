// Fill out your copyright notice in the Description page of Project Settings.

#include "MemeMe.h"
#include "PluginComponent.h"

// Sets default values
APluginComponent::APluginComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APluginComponent::BeginPlay()
{
	Super::BeginPlay();
	GLog->Log("BeginPlay in your Awesome Plugin Component has fired!");

	
}

// Called every frame
void APluginComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

