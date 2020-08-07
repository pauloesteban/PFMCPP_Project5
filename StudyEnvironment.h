#pragma once

#include "LeakedObjectDetector.h"
#include "Housing.h"
#include "Ipad.h"

struct StudyEnvironment
{
    Housing housing;
    Ipad iPad;

    StudyEnvironment();
    ~StudyEnvironment();

    JUCE_LEAK_DETECTOR( StudyEnvironment )
};

