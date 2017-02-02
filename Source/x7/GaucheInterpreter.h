// -*- c++ -*-
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GaucheObj.h"
#include "GaucheInterpreter.generated.h"

UCLASS()
class X7_API AGaucheInterpreter : public AActor
{
    GENERATED_BODY()

 public:	
    // Sets default values for this actor's properties
    AGaucheInterpreter();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
	
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION(BlueprintCallable, Category="Gauche")
	static UGaucheObj* EvalString(const FString &expr);

    UFUNCTION(BlueprintCallable, Category="Gauche")
	static UGaucheObj* Apply(UGaucheObj *proc, TArray<UGaucheObj*> args);

    UFUNCTION(BlueprintCallable, Category="Gauche")
	static FString AsString(UGaucheObj *obj);

    UFUNCTION(BlueprintCallable, Category="Gauche")
	static float AsFloat(UGaucheObj *obj);

private:

    class GaucheState {
    public:
	GaucheState();
    };

    static GaucheState* state() {
	static GaucheState *st = NULL;
	if (!st) {
	    st = new GaucheState();
	}
	return st;
    };
};


// Local Variables:
// c-basic-offset: 4;
// End:
