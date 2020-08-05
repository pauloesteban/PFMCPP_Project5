#pragma once

#include "LeakedObjectDetector.h"
#include "NestedWrappers.h"

struct MobilePhone
{
    int typeOfNetwork = 4;
    float retailPrice = 0.0f;
    float usageInHours;
    bool isAndroid;
    float remainingBattery;

    DataPlanWrapper dataPlan;
    
    MobilePhone( bool isAndroid );
    ~MobilePhone();
    
    void setRetailPrice( float price );
    float getCurrentPrice( float depreciation );
    float getRemainingBattery( int usageHours, bool isCharging = false );
    void printRemainingBattery();

    JUCE_LEAK_DETECTOR( MobilePhone )
};

