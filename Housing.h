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

