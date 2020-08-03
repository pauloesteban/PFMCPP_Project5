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

MobilePhone::DataPlan::DataPlan()
: downloadSpeed( 50.0f ),
  balanceInGBytes( 0.0f ),
  balanceInUSD( 0.0f )
{
    std::cout << "Empty DataPlan ctor" << std::endl;
}

MobilePhone::DataPlan::~DataPlan()
{
    std::cout<< "DataPlan dtor" << std::endl;
}

void MobilePhone::DataPlan::addBalance( float balance , bool isBeforeRollOver )
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

float MobilePhone::DataPlan::getRemainingGigaBytes()
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

float MobilePhone::DataPlan::getDownloadSpeed( int availableNetwork )
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

