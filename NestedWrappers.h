#pragma once

#include "Room.h"
#include "DataPlan.h"

struct RoomWrapper
{
    RoomWrapper( Room* ptr );
    ~RoomWrapper();

    Room* roomPtr = nullptr;
};

struct DataPlanWrapper
{
    DataPlanWrapper( DataPlan* ptr );
    ~DataPlanWrapper();

    DataPlan* dataPlanPtr = nullptr;
};
