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
    UE_LOG(LogTemp, Warning, TEXT("Gauche state: %p"), stat);

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

static void ShowError(ScmObj c)
{
    ScmObj m = Scm_ConditionMessage(c);
    if (SCM_FALSEP(m)) {
        Scm_Printf(SCM_CURERR, "gosh: Thrown unknown condition: %S\n", c);
    } else {
        Scm_Printf(SCM_CURERR, "gosh: %S: %A\n", Scm_ConditionTypeName(c), m);
    }
}

UGaucheObj* AMyActor::EvalString(const FString &expr)
{
    ScmEvalPacket epak;
    UGaucheObj *obj = NewObject<UGaucheObj>();

    if (Scm_EvalCString(TCHAR_TO_ANSI(*expr), SCM_OBJ(Scm_UserModule()), &epak) < 0) {
        ShowError(epak.exception);
        obj->setScmObj(SCM_NIL);
    } else {
        UE_LOG(LogTemp, Log, TEXT("EvalString: %s"), *expr);
        obj->setScmObj(epak.results[0]);
    }

    return obj;
}

UGaucheObj* AMyActor::Apply(UGaucheObj *proc, TArray<UGaucheObj*> args)
{
    ScmEvalPacket epak;
    ScmObj argList = SCM_NIL;
    for (auto arg : args) {
	argList = Scm_Cons(arg->getScmObj(), argList);
    }
    // ScmObj result = Scm_ApplyRec(proc->getScmObj(), argList);
    UGaucheObj *obj = NewObject<UGaucheObj>();
    if (Scm_ApplyRec(proc->getScmObj(), argList) < 0) {
        ShowError(epak.exception);
        obj->setScmObj(SCM_NIL);
    } else {
        obj->setScmObj(epak.results[0]);
    }
    return obj;
}

FString AMyActor::AsString(UGaucheObj *obj)
{
    ScmObj o = obj->getScmObj();
    if (!o || !SCM_STRINGP(o)) {
        return FString("");
    }

    return FString(SCM_STRING_BODY_START(SCM_STRING_BODY(o)));
}

float AMyActor::AsFloat(UGaucheObj *obj)
{
    ScmObj o = obj->getScmObj();
    if (SCM_FLONUMP(o)) {
        return float(SCM_FLONUM_VALUE(o));
    }

    if (SCM_INTP(o)) {
        return float(SCM_INT_VALUE(o));
    }

    return 0;
}

AMyActor::GaucheState::GaucheState()
{
    SCM_INIT_STATIC();
}



// Local Variables:
// c-basic-offset: 4;
// End:
