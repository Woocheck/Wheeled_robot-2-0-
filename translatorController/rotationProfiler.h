#ifndef __ROTATION_PROFILER__
#define __ROTATION_PROFILER__

#include "./profiler.h"

class RotationProfiler: public Profiler
{
    TranslationProfiler(int acceleration , int target):
    {
        Profiler( acceleration, targetSpeed );
    }

    private:
    int calculateNextStepSeed();
} 

#endif