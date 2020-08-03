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

