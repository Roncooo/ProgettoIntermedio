#include "Date.h"


Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
    if(y < 0)
        throw new InvalidYearException();
    
}

bool Date::is_bisestile()
{
    if((this->year % 100 == 0) && (this->year % 400 == 0)) //se un anno è divisibile per 100 e per 400 è bisestile
        return true;
    else if(this->year % 4 == 0) //se un anno è divisibile per 4 è bisestile
        return true;
    return false;
}

bool Date::check_february()
{
    if((this->mon == feb) && this->is_bisestile())
    {
        if(this->day > max_day_feb)
            throw new FebruaryException();
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, Date d)
{
    return os<<d.get_day()<<", "<<d.get_month()<<", "<<d.get_year()<<"\n"; 
}


