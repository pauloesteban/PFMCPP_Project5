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

