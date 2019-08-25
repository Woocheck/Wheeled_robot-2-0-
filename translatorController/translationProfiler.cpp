#include "./profiler.h"
#include "./translationProfiler.h"

int TranslationProfiler::calculateNextStepSeed()
{
    return Profiler::currentSpeed_;
}