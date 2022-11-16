#include "Date.h"


Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
    if(y < 0)
        throw new InvalidYearException();
    
}

bool Date::is_bisestile()
{
    return false;
}



Date::~Date()
{
}

