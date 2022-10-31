/**
 * @file FoeTracker.cpp
 * @author zhiqiang ni
 */

#include "pch.h"
#include "FoeTracker.h"
#include "Foe.h"

void FoeTracker::VisitFoe(Foe* foe)
{
    mNumberFoe++;
}