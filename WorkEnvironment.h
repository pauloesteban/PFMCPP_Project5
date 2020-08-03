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

