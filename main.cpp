/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

#include <iostream>
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
    };
    
    bool isRented = false;
    float weeklyFee;
    float yearNetFees;
    bool areServicesIncluded = false;
    float increasePercentage;

    Room room;
    
    Housing( float weeklyFee, float increasePercentage, bool includeServices );
    ~Housing();
    
    float monthlyFee();
    void setWeeklyFee( float fee );
    void projectedFees( int planedYearsOfRental );
    void printYearNetFees();
};

Housing::Housing( float fee, float percentage, bool includeServices )
:  weeklyFee( fee ),
   yearNetFees (12.0f * weeklyFee),
   areServicesIncluded( includeServices ),
   increasePercentage( percentage ),
   room( false, 1 )
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
    };
    
    int typeOfNetwork = 4;
    float retailPrice = 0.0f;
    float usageInHours;
    bool isAndroid;
    float remainingBattery;

    DataPlan dataPlan;
    
    MobilePhone( bool isAndroid );
    ~MobilePhone();
    
    void setRetailPrice( float price );
    float getCurrentPrice( float depreciation );
    float getRemainingBattery( int usageHours, bool isCharging = false );
    void printRemainingBattery();
};

MobilePhone::MobilePhone( bool isAndroidInstalled )
: usageInHours( 0 ),
  isAndroid( isAndroidInstalled ),
  remainingBattery( 100.0f )
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
    std::cout << "This WAS a work environment in a room w/ " << housing.room.windows << " windows."<< std::endl;
}

void WorkEnvironment::printHousingYearNetFees()
{
    this->housing.printYearNetFees();
}

void WorkEnvironment::printMobilePhoneRemainingBatt()
{
    this->mobilePhone.printRemainingBattery();
}

/*
 new UDT 5:
 */
struct StudyEnvironment
{
    Housing housing;
    Ipad iPad;

    StudyEnvironment();
    ~StudyEnvironment();
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
    Ipad iPadMini1( 9.0f, "0000" );
    Ipad iPadMini4( 13.1f, "5757" );
    Housing studentHousing( 50.0f, 0.0f, true );
    Housing coupleHousing( 200.0f, 10.0f, false );
    MobilePhone xiaomi4X( true );
    MobilePhone iPhone6S( false );

    WorkEnvironment officeForPaulo;
    WorkEnvironment officeForDiana;
    StudyEnvironment lectureSpace;
    StudyEnvironment zoomMeetingSpace;

    iPadMini1.installApps( 1 );
    iPadMini4.installApps( 10 );
    xiaomi4X.setRetailPrice( 150.0f );
    iPhone6S.setRetailPrice( 500.0f );

    std::cout << "=======================================" << std::endl;
    std::cout << "iPad Mini 1 apps = " << iPadMini1.installedApps << std::endl;
    iPadMini1.printInstalledApps();
    std::cout << "iPad Mini 4 apps = " << iPadMini4.installedApps << std::endl;
    iPadMini4.printInstalledApps();
    std::cout << "Paulo's office year net fees (USD) = " << officeForPaulo.housing.yearNetFees << std::endl;
    officeForPaulo.printHousingYearNetFees();
    std::cout << "Remaining battery for Diana (%) = " << officeForDiana.mobilePhone.getRemainingBattery( 5, false ) << std::endl;
    officeForDiana.printMobilePhoneRemainingBatt();
    std::cout << "=======================================" << std::endl;

    std::cout << "good to go!" << std::endl;
}
