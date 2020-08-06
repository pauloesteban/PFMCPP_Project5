#pragma once

#include "Room.h"
struct DataPlan;

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
