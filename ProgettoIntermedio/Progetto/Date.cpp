#include "Date.h"

Date::Date(int d, Month m, int y) //siccome devo fare una verifica sugli argomenti non ha senso fare un'init list
{
	if(!is_valid_date(d, m, y))
		throw new InvalidDateException();
	else
    {
        day = d;
        mon = m;
        year = y;
    }
}

// costruttore che prende anche il mese passato per intero
Date::Date(int d, int m, int y)
{
	if(!is_valid_date(d, Month(m), y))
		throw new InvalidDateException();
	else
    {
        day = d;
        mon = Month(m);
        year = y;
    }
}

// funzione statica che controlla l'anno bisestile
bool Date::is_leap_year(int y)
{
	if((y % 100 == 0) && (y % 400 != 0)) //se un anno è divisibile per 100 e per 400 è bisestile
		return false;
	
	if(y % 4 == 0) //se un anno è divisibile per 4 è bisestile
		return true;
	
	return false;
}

//funzione statica che controlla la validità della data
bool Date::is_valid_date(int d, Month m, int y)
{
	if(y > next_year || y < 0)
		return false;
	else if(m < 1 || m > 12)
		return false;
	else if(d < 0 || d > 31)
		return false;
	
	// controlli sui vari mesi
	if( (is_leap_year(y)) && (m == feb) )  
	{
		if(d > max_day_feb)  
			return false;
		return true;
	}
	else if( (!is_leap_year(y)) && (m == feb) )
	{
		if(d > max_day_feb-1)
			return false;
		return true;
	}
	if(m == apr || m == jun || m == sep || m == nov)
	{
		if(d > 30)
			return false;
	}
	return true;
}

// ***OVERLOADING OPERATORI***
std::ostream& operator<<(std::ostream& os, Date d)
{
	return os<<d.get_day()<<"/"<<d.get_month()<<"/"<<d.get_year(); 
}

bool operator<(Date first, Date second)
{
    if( first.get_year() < second.get_year() )
        return true;
    if( first.get_month() < second.get_month() )
		return true;
	if( first.get_day() < second.get_day() )
		return true;
	return false;
}

bool operator>(Date first, Date second)
{
	return second < first;
}

bool operator==(Date first, Date second)
{
    return ( !(first > second) && !(first < second) );
}

bool operator!=(Date first, Date second)
{
    return !(first == second);
}

// costruttore di spostamento
Date::Date(Date&& d)
{
	
}

//assegnamento di spostamento
Date& Date::operator=(Date&& d)
{
	
}

// costruttore di copia necessario a causa di Month che non è built-in
Date::Date(const Date& d) 
	:day{d.day}, mon{d.mon}, year{d.year}
{
	// constructor body, intentionally left blank
}

//assegnamento di copia necessario a causa di Month che non è built-in
Date& Date::operator=(const Date& d)
{
	this->day = d.day;
	this->mon = d.mon;
	this->year = d.year; 
}
