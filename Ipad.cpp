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
