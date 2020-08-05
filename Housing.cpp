#include "Housing.h"
#include "Room.h"

Housing::Housing( float fee, float percentage, bool includeServices )
:  weeklyFee( fee ),
   yearNetFees (12.0f * weeklyFee),
   areServicesIncluded( includeServices ),
   increasePercentage( percentage ),
   room( new Room( false, 1 ) )
{
    std::cout << "Housing at USD " << weeklyFee << "per week, ctor." << std::endl;
}

Housing::~Housing()
{
    std::cout << "Housing dtor." << std::endl;
}

float Housing::monthlyFee()
{
    return weeklyFee * 4.0f;
}

void Housing::setWeeklyFee( float fee )
{
    if( areServicesIncluded )
    {
        weeklyFee = fee * 1.2f;
    }
    else
    {
        weeklyFee = fee;
    }

    std::cout << "Your weekly fee is USD " << weeklyFee << std::endl;
}

void Housing::projectedFees( int plannedYearsOfRental )
{
    yearNetFees = 12.0f * monthlyFee();
    
    for( int i = 0; i < plannedYearsOfRental; ++i )
    {
        float yearFeesFinal = (1.0f + increasePercentage) * yearNetFees;
        std::cout << "Year " << i + 1 << ": " << yearFeesFinal << std::endl;
        yearNetFees = yearFeesFinal;
    }
}

void Housing::printYearNetFees()
{
    std::cout << "Housing year net fees (USD) = " << this->yearNetFees << std::endl;   
}

