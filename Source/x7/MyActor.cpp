// Fill out your copyright notice in the Description page of Project Settings.

#include "x7.h"
#include "MyActor.h"
#include "GaucheObj.h"
#include <gauche.h>
#include <gauche/static.h>

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this
    // off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    GaucheState *stat = state();
    UE_LOG(LogTemp, Warning, TEXT("2 Gauche state: %p"), stat);

    // ScmEvalPacket pack;
    // int32 num = Scm_EvalCString("(diplay 12345)", SCM_OBJ(Scm_UserModule()), &pack);
    // UE_LOG(LogTemp, Warning, TEXT("Gauche ret: %d"), num);
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

int32 AMyActor::Eval(const FString &expr)
{
    ScmEvalPacket pack;
    int32 num = Scm_EvalCString(TCHAR_TO_ANSI(*expr), SCM_OBJ(Scm_UserModule()), &pack);
    UE_LOG(LogTemp, Log, TEXT("Evaled: %d: %s"), num, *expr);
    return num;
}

UGaucheObj* AMyActor::EvalString(const FString &expr)
{
    ScmObj result = Scm_EvalCStringRec(TCHAR_TO_ANSI(*expr), SCM_OBJ(Scm_UserModule()));
    UE_LOG(LogTemp, Log, TEXT("EvalString: %s"), *expr);
    UGaucheObj *obj = NewObject<UGaucheObj>();
    obj->setScmObj(result);
    return obj;
}

UGaucheObj* AMyActor::Apply(UGaucheObj *proc, TArray<UGaucheObj*> args)
{
    ScmObj argList = SCM_NIL;
    for (auto arg : args) {
	argList = Scm_Cons(arg->getScmObj(), argList);
    }
    ScmObj result = Scm_ApplyRec(proc->getScmObj(), argList);

    UGaucheObj *obj = NewObject<UGaucheObj>();
    obj->setScmObj(result);
    return obj;
}

AMyActor::GaucheState::GaucheState()
{
    SCM_INIT_STATIC();
}



// Local Variables:
// c-basic-offset: 4;
// End:
