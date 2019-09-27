#include "./profiler.h"
#include "./translationProfiler.h"

int TranslationProfiler::calculateNextStepSeed()
{
    return  Profiler::passedRoad_;
}