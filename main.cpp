/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */








#include <iostream>
#include "LeakedObjectDetector.h"
/*
 UDT 1:
 */
struct Ipad
{
    int installedApps = 0;
    float iosMajorVersion;
    std::string fourDigitPasscode;
    bool isBackedUp = true;
    bool isProModel = false;
    
    Ipad( float version, std::string passcode );
    ~Ipad();
    
    bool updateIos( float version, bool isEnoughStorage = true );
    void setIpadModel( bool isPro );
    void installApps( int newApps );
    void printInstalledApps();

    JUCE_LEAK_DETECTOR( Ipad )
};

Ipad::Ipad( float version, std::string passcode)
: iosMajorVersion( version ),
  fourDigitPasscode( passcode )
{
    std::cout << "iPad " << iosMajorVersion << " ctor" << std::endl;
}

Ipad::~Ipad()
{
    std::cout << "iPad " << iosMajorVersion << " dtor" << std::endl;
}

bool Ipad::updateIos( float version, bool isEnoughStorage )
{
    if( isEnoughStorage )
    {
        if( iosMajorVersion < version )
        {
            std::cout << "Upgrading to iOS " << version << "." << std::endl;
            iosMajorVersion = version;
            return true;
        }
        else
        {
            std::cout << "iPad already on latest iOS version." << std::endl;
            return false;
        }
    }

    std::cout << "Not enough space for upgrading." << std::endl;
    return false;
}

void Ipad::setIpadModel( bool isPro )
{
    isProModel = isPro;
    auto model = isProModel ? "iPad Pro." : "normal iPad.";

    std::cout << "You have " << model << std::endl;
}

void Ipad::installApps( int newApps )
{
    for( int i = 0; i < newApps; ++i )
    {
        std::cout << "Installing app " << i + 1 << " out of " << newApps << std::endl;
        ++installedApps;
        std::cout << "Total Installed Apps: " << installedApps << std::endl;
    }
}

void Ipad::printInstalledApps()
{
    std::cout << "iPad apps = " << this->installedApps << std::endl;
}

struct IpadWrapper
{
    IpadWrapper( Ipad* ptr ) : iPadPtr( ptr )
    {

    }

    ~IpadWrapper()
    {
        delete iPadPtr;
    }

    Ipad* iPadPtr = nullptr;
};

/*
 UDT 2:
 */
struct Housing
{
    struct Room
    {
        bool hasIndependentBathroom;
        bool hasCCTV = false;
        int windows = 1;
        int bedSize;
        float areaInSqFt = 20;

        Room( bool independentBathroom, int sizeOfBed );
        ~Room();

        void installMoreWindows( int additionalWindows = 1 );
        void installCCTV();
        void changeBed( int newBedSize );

        JUCE_LEAK_DETECTOR( Room )
    };

    struct RoomWrapper
    {
        RoomWrapper( Room* ptr ) : roomPtr( ptr )
        {

        }

        ~RoomWrapper()
        {
            delete roomPtr;
        }

        Room* roomPtr = nullptr;
    };
    
    bool isRented = false;
    float weeklyFee;
    float yearNetFees;
    bool areServicesIncluded = false;
    float increasePercentage;

    RoomWrapper room;
    
    Housing( float weeklyFee, float increasePercentage, bool includeServices );
    ~Housing();
    
    float monthlyFee();
    void setWeeklyFee( float fee );
    void projectedFees( int planedYearsOfRental );
    void printYearNetFees();

    JUCE_LEAK_DETECTOR( Housing )
};

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

Housing::Room::Room( bool independentBathroom, int sizeOfBed )
: hasIndependentBathroom( independentBathroom ),
  bedSize( sizeOfBed )
{
    std::cout << "A " << areaInSqFt << " per week with " << windows << " windows." << std::endl;
}

Housing::Room::~Room()
{
    std::cout << "Room dtor" << std::endl;
}

void Housing::Room::installMoreWindows( int additionalWindows )
{
    windows += additionalWindows;
}

void Housing::Room::installCCTV()
{
    hasCCTV = true;
}

void Housing::Room::changeBed( int newBedSize )
{
    bedSize = newBedSize;
    std::cout << "Be aware. Free space in your room has changed." << std::endl;
}

struct HousingWrapper
{
    HousingWrapper( Housing* ptr ) : housingPtr( ptr )
    {

    }

    ~HousingWrapper()
    {
        delete housingPtr;
    }

    Housing* housingPtr = nullptr;
};

/*
 UDT 3:
 */
struct MobilePhone
{
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

    struct DataPlanWrapper
    {
        DataPlanWrapper( DataPlan* ptr ) : dataPlanPtr( ptr )
        {

        }

        ~DataPlanWrapper()
        {
            delete dataPlanPtr;
        }

        DataPlan* dataPlanPtr = nullptr;
    };
    
    int typeOfNetwork = 4;
    float retailPrice = 0.0f;
    float usageInHours;
    bool isAndroid;
    float remainingBattery;

    DataPlanWrapper dataPlan;
    
    MobilePhone( bool isAndroid );
    ~MobilePhone();
    
    void setRetailPrice( float price );
    float getCurrentPrice( float depreciation );
    float getRemainingBattery( int usageHours, bool isCharging = false );
    void printRemainingBattery();

    JUCE_LEAK_DETECTOR( MobilePhone )
};

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

struct MobilePhoneWrapper
{
    MobilePhoneWrapper( MobilePhone* ptr ) : mobilePhonePtr( ptr )
    {

    }

    ~MobilePhoneWrapper()
    {
        delete mobilePhonePtr;
    }

    MobilePhone* mobilePhonePtr = nullptr;
};

/*
 new UDT 4:
 */
struct WorkEnvironment
{
    Housing housing;
    MobilePhone mobilePhone;
    Ipad iPad;

    WorkEnvironment();
    ~WorkEnvironment();

    void printMobilePhoneRemainingBatt();
    void printHousingYearNetFees();

    JUCE_LEAK_DETECTOR( WorkEnvironment )
};

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

struct WorkEnvironmentWrapper
{
    WorkEnvironmentWrapper( WorkEnvironment* ptr ) : workEnvironmentPtr( ptr )
    {

    }

    ~WorkEnvironmentWrapper()
    {
        delete workEnvironmentPtr;
    }

    WorkEnvironment* workEnvironmentPtr = nullptr;
};

/*
 new UDT 5:
 */
struct StudyEnvironment
{
    Housing housing;
    Ipad iPad;

    StudyEnvironment();
    ~StudyEnvironment();

    JUCE_LEAK_DETECTOR( StudyEnvironment )
};

StudyEnvironment::StudyEnvironment()
: housing( 50.0f, 0.0f, true ),
  iPad( 13.1f, "4857" )
{
    std::cout << "This is a study environment" << std::endl;
}

StudyEnvironment::~StudyEnvironment()
{
    std::cout << "This WAS a study environment for USD " << housing.monthlyFee() << " per month" << std::endl;
}

struct StudyEnvironmentWrapper
{
    StudyEnvironmentWrapper( StudyEnvironment* ptr ) : studyEnvironmentPtr( ptr )
    {

    }

    ~StudyEnvironmentWrapper()
    {
        delete studyEnvironmentPtr;
    }

    StudyEnvironment* studyEnvironmentPtr = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
int main()
{
    IpadWrapper iPadMini1( new Ipad( 9.0f, "0000" ) );
    IpadWrapper iPadMini4( new Ipad( 13.1f, "5757" ) );
    HousingWrapper studentHousing( new Housing( 50.0f, 0.0f, true ) );
    HousingWrapper coupleHousing( new Housing( 200.0f, 10.0f, false ) );
    MobilePhoneWrapper xiaomi4X( new MobilePhone( true ) );
    MobilePhoneWrapper iPhone6S( new MobilePhone( false ) );

    WorkEnvironmentWrapper officeForPaulo( new WorkEnvironment() );
    WorkEnvironmentWrapper officeForDiana( new WorkEnvironment() );
    StudyEnvironmentWrapper lectureSpace( new StudyEnvironment() );
    StudyEnvironmentWrapper zoomMeetingSpace( new StudyEnvironment() );

    iPadMini1.iPadPtr->installApps( 1 );
    iPadMini4.iPadPtr->installApps( 10 );
    xiaomi4X.mobilePhonePtr->setRetailPrice( 150.0f );
    iPhone6S.mobilePhonePtr->setRetailPrice( 500.0f );

    std::cout << "=======================================" << std::endl;
    std::cout << "iPad Mini 1 apps = " << iPadMini1.iPadPtr->installedApps << std::endl;
    iPadMini1.iPadPtr->printInstalledApps();
    std::cout << "iPad Mini 4 apps = " << iPadMini4.iPadPtr->installedApps << std::endl;
    iPadMini4.iPadPtr->printInstalledApps();
    std::cout << "Paulo's office year net fees (USD) = " << officeForPaulo.workEnvironmentPtr->housing.yearNetFees << std::endl;
    officeForPaulo.workEnvironmentPtr->printHousingYearNetFees();
    std::cout << "Remaining battery for Diana (%) = " << officeForDiana.workEnvironmentPtr->mobilePhone.getRemainingBattery( 5, false ) << std::endl;
    officeForDiana.workEnvironmentPtr->printMobilePhoneRemainingBatt();
    std::cout << "=======================================" << std::endl;

    std::cout << "good to go!" << std::endl;
}
