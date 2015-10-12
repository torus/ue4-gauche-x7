// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <gauche.h>
#include "GaucheObj.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class X7_API UGaucheObj : public UObject
{
    GENERATED_BODY()

public:
    UGaucheObj();
    ~UGaucheObj();

    ScmObj getScmObj() const {return scmObj_;}
    void setScmObj(const ScmObj &obj) {scmObj_ = obj;}

private:
    ScmObj scmObj_;

    // hide default constructor.
};

// Local Variables:
// mode: c++;
// c-basic-offset: 4;
// End:
