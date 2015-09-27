// Fill out your copyright notice in the Description page of Project Settings.

#include "x7.h"
#include "MyActor.h"
#include <gauche.h>
#include <gauche/static.h>

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
}

AMyActor::Initializer AMyActor::initializer;

AMyActor::Initializer::Initializer()
{
    SCM_INIT_STATIC();
}
