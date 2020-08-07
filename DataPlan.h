#pragma once

#include "LeakedObjectDetector.h"

struct DataPlan
{
    bool isPrepaid = true;
    bool isRollOver = true;
    float downloadSpeed;
    float balanceInGBytes;
    float balanceInUSD;

    DataPlan();
    ~DataPlan();

    void addBalance( float balance = 1.0f, bool isBeforeRollOver = true );
    float getRemainingGigaBytes();
    float getDownloadSpeed( int availableNetwork = 4 );

    JUCE_LEAK_DETECTOR( DataPlan )
};

