#pragma once

struct Ipad;
struct Housing;
struct MobilePhone;
struct WorkEnvironment;
struct StudyEnvironment;

struct IpadWrapper
{
    IpadWrapper( Ipad* ptr );
    ~IpadWrapper();

    Ipad* iPadPtr = nullptr;
};

struct HousingWrapper
{
    HousingWrapper( Housing* ptr );
    ~HousingWrapper();

    Housing* housingPtr = nullptr;
};

struct MobilePhoneWrapper
{
    MobilePhoneWrapper( MobilePhone* ptr );
    ~MobilePhoneWrapper();

    MobilePhone* mobilePhonePtr = nullptr;
};

struct WorkEnvironmentWrapper
{
    WorkEnvironmentWrapper( WorkEnvironment* ptr );
    ~WorkEnvironmentWrapper();

    WorkEnvironment* workEnvironmentPtr = nullptr;
};

struct StudyEnvironmentWrapper
{
    StudyEnvironmentWrapper( StudyEnvironment* ptr );
    ~StudyEnvironmentWrapper();

    StudyEnvironment* studyEnvironmentPtr = nullptr;
};


