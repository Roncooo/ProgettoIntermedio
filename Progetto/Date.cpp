#include "Date.h"


Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
    if(y < 0)
        throw new InvalidYearException();
    
}

bool Date::is_bisestile()
{
    if((this->year % 100 == 0) && this->year % 400 == 0)) //se un anno è divisibile per 100 e per 400 è bisestile
        return true;
    else if(this->year % 4 == 0) //se un anno è divisibile per 4 è bisestile
        return true;
    return false;
}

bool Date::check_february() // non è meglio un check_days_of_month che controlla per esempio che per gennaio ci siano <= 31 giorni, per febbraio i controlli del caso, etc...?
{
    if((this->mon == feb) && (is_bisestile(this->year)))
    {
        if(this->day > max_day_feb)
            throw new FebruaryException();
    }
    return true;
}



