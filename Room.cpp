#include "Room.h"

Room::Room( bool independentBathroom, int sizeOfBed )
: hasIndependentBathroom( independentBathroom ),
  bedSize( sizeOfBed )
{
    std::cout << "A " << areaInSqFt << " per week with " << windows << " windows." << std::endl;
}

Room::~Room()
{
    std::cout << "Room dtor" << std::endl;
}

void Room::installMoreWindows( int additionalWindows )
{
    windows += additionalWindows;
}

void Room::installCCTV()
{
    hasCCTV = true;
}

void Room::changeBed( int newBedSize )
{
    bedSize = newBedSize;
    std::cout << "Be aware. Free space in your room has changed." << std::endl;
}

