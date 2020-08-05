#pragma once

#include "LeakedObjectDetector.h"

struct Room
{
    bool hasIndependentBathroom;
    bool hasCCTV = false;
    int windows = 1;
    int bedSize;
    float areaInSqFt = 20;

    Room( bool independentBathroom, int sizeOfBed );
    ~Room();

    void installMoreWindows( int additionalWindows = 1 );
    void installCCTV();
    void changeBed( int newBedSize );

    JUCE_LEAK_DETECTOR( Room )
};
