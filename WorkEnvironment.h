#pragma once

#include "Housing.h"
#include "MobilePhone.h"
#include "Ipad.h"
#include "LeakedObjectDetector.h"

struct WorkEnvironment
{
    Housing housing;
    MobilePhone mobilePhone;
    Ipad iPad;

    WorkEnvironment();
    ~WorkEnvironment();

    void printMobilePhoneRemainingBatt();
    void printHousingYearNetFees();

    JUCE_LEAK_DETECTOR( WorkEnvironment )
};

