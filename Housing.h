#pragma once

#include "LeakedObjectDetector.h"
#include "NestedWrappers.h"

struct Housing
{
    bool isRented = false;
    float weeklyFee;
    float yearNetFees;
    bool areServicesIncluded = false;
    float increasePercentage;

    RoomWrapper room;
    
    Housing( float weeklyFee, float increasePercentage, bool includeServices );
    ~Housing();
    
    float monthlyFee();
    void setWeeklyFee( float fee );
    void projectedFees( int planedYearsOfRental );
    void printYearNetFees();

    JUCE_LEAK_DETECTOR( Housing )
};

