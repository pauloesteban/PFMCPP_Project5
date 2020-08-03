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

/*
 UDT 2:
 */

/*
 UDT 3:
 */

/*
 new UDT 4:
 */

/*
 new UDT 5:
 */

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
