// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectiveActor.h"
#include "Components/StaticMeshComponents.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor(ECollisionEnabled::NoCollision)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
  MeshComp->SetCollisionEnabled()
  RootComponent = MeshComp;

  SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
  SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
  SphereComp->SetCollisionResponseToAllChannels(ECC_Pawn, ECR_Overlap);
  SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();

  PlayEffects();

}

void AFPSObjectiveActor::PlayEffects()
{
  UGamePlayStatics::SpawnEmitteratLocation(this, PickupFX, GetActorLocation());
}

// Called every frame
void AFPSObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

