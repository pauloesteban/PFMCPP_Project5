#include "WorkEnvironment.h"

WorkEnvironment::WorkEnvironment()
: housing( 100.0f, 5.0f, false ),
  mobilePhone( true ),
  iPad( 13.1f, "8898" )
{
    std::cout << "This is a work environment" << std::endl;
}

WorkEnvironment::~WorkEnvironment()
{
    std::cout << "This WAS a work environment in a room w/ " << housing.room.roomPtr->windows << " windows."<< std::endl;
}

void WorkEnvironment::printHousingYearNetFees()
{
    this->housing.printYearNetFees();
}

void WorkEnvironment::printMobilePhoneRemainingBatt()
{
    this->mobilePhone.printRemainingBattery();
}

