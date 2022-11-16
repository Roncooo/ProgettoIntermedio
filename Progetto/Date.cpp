#include "Date.h"

Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
    if(y < first_copyright_year || y > current_year)
    {
        throw InvalidYearException(); 
    }
    
}

Date::~Date()
{
}

