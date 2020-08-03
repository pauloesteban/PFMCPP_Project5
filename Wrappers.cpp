IpadWrapper::IpadWrapper( Ipad* ptr ) : iPadPtr( ptr )
{

}

IpadWrapper::~IpadWrapper()
{
    delete iPadPtr;
}


HousingWrapper::HousingWrapper( Housing* ptr ) : housingPtr( ptr )
{

}

HousingWrapper::~HousingWrapper()
{
    delete housingPtr;
}


MobilePhoneWrapper::MobilePhoneWrapper( MobilePhone* ptr ) : mobilePhonePtr( ptr )
{

}

MobilePhoneWrapper::~MobilePhoneWrapper()
{
    delete mobilePhonePtr;
}


WorkEnvironmentWrapper::WorkEnvironmentWrapper( WorkEnvironment* ptr ) : workEnvironmentPtr( ptr )
{

}

WorkEnvironmentWrapper::~WorkEnvironmentWrapper()
{
    delete workEnvironmentPtr;
}


StudyEnvironmentWrapper::StudyEnvironmentWrapper( StudyEnvironment* ptr ) : studyEnvironmentPtr( ptr )
{

}

StudyEnvironmentWrapper::~StudyEnvironmentWrapper()
{
    delete studyEnvironmentPtr;
}