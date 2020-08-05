#include "DataPlan.h"

DataPlan::DataPlan()
: downloadSpeed( 50.0f ),
  balanceInGBytes( 0.0f ),
  balanceInUSD( 0.0f )
{
    std::cout << "Empty DataPlan ctor" << std::endl;
}

DataPlan::~DataPlan()
{
    std::cout<< "DataPlan dtor" << std::endl;
}

void DataPlan::addBalance( float balance , bool isBeforeRollOver )
{
    if( isBeforeRollOver && isRollOver )
    {
        balanceInUSD += balance;
    }
    else
    {
        balanceInUSD = balance;
    }

    balanceInGBytes = 2.0f * balance;
}

float DataPlan::getRemainingGigaBytes()
{
    if( isPrepaid )
    {
        return balanceInGBytes;
    }
    else
    {
        std::cout << "You have a contract with unlimited data!" << std::endl;

        return 0.0f;
    }
}

float DataPlan::getDownloadSpeed( int availableNetwork )
{
    switch( availableNetwork )
    {
        case 2:
            return downloadSpeed / 4.0f;
        case 3:
            return downloadSpeed / 2.0f;
        default:
            return downloadSpeed;
    }
}
