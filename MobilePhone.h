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

