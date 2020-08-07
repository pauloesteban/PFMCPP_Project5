#include "MobilePhone.h"
#include "DataPlan.h"

MobilePhone::MobilePhone( bool isAndroidInstalled )
: usageInHours( 0 ),
  isAndroid( isAndroidInstalled ),
  remainingBattery( 100.0f ),
  dataPlan( new DataPlan() )
{
    auto typeOfPhone = isAndroid ? "Android" : "iPhone";
    std::cout << "Your mobile is an" << typeOfPhone << std::endl;
}

MobilePhone::~MobilePhone()
{
    std::cout << "Phone dtor" << std::endl;
}

void MobilePhone::setRetailPrice( float price )
{
    retailPrice = price;
}

float MobilePhone::getCurrentPrice( float depreciation )
{
    if (isAndroid)
    {
        return retailPrice * (1.0f - 0.01f * depreciation);
    }

    return retailPrice;
}

float MobilePhone::getRemainingBattery( int usageHours, bool isCharging )
{
    usageInHours = static_cast<float>( usageHours );

    if ( ! isCharging )
    {
        for (int i = 0; i < usageHours; ++i)
        {
            remainingBattery *= 0.95f;
        }
    }

    return remainingBattery;
}

void MobilePhone::printRemainingBattery()
{
    std::cout << "Mobile phone remaining battery (%) = " << this->remainingBattery << std::endl;
}

