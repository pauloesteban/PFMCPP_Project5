#pragma once

struct Room;
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
