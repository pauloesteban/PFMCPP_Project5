#include "NestedWrappers.h"
#include "DataPlan.h"

RoomWrapper::RoomWrapper( Room* ptr ) : roomPtr( ptr )
{

}

RoomWrapper::~RoomWrapper()
{
    delete roomPtr;
}

DataPlanWrapper::DataPlanWrapper( DataPlan* ptr ) : dataPlanPtr( ptr )
{

}

DataPlanWrapper::~DataPlanWrapper()
{
    delete dataPlanPtr;
}
