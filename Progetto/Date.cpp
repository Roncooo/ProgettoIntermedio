#include "Date.h"

Date::Date(int d, Month m, int y)	// non ha senso l'initializer list perché bisogna prima controllare i dati
{
	if(!is_valid_date(d, m, y))
		throw new InvalidDateException();
	// else
	day = d;
	mon = m;
	year = y;
}

Date::Date(int d, int m, int y)
{
	if(!is_valid_date(d, Month(m), y))
		throw new InvalidDateException();
	// else
	day = d;
	mon = Month(m);
	year = y;
}

// costruttore di spostamento
Date::Date(Date&& d)
{
	// DA FARE ?
}

//assegnamento di spostamento
Date& Date::operator=(Date&& d)
{
	// DA FARE ?
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

bool Date::is_leap_year(int y)
{
	// se un anno è divisibile per 100 ma non per 400, non è bisestile
	if((y % 100 == 0) && (y % 400 != 0))
		return false;
	// se un anno è divisibile per 4 è bisestile
	if(y % 4 == 0)
		return true;
	
	return false;
}

bool Date::is_valid_date(int d, Month m, int y)
{
	if(y > next_year || y < 0)
		return false;
	else if(m < 1 || m > 12)
		return false;
	else if(d < 0 || d > 31)
		return false;
	
	// controlli sui singoli mesi
	if((is_leap_year(y)) && (m == feb))  
	{
		if(d > max_day_feb)  
			return false;
		return true;
	}
	else if((!is_leap_year(y)) && (m == feb))
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

// overloading operatori
bool operator<(Date first, Date second)
{
    if(first.get_year() < second.get_year())
        return true;
    if(first.get_month() < second.get_month())
		return true;
	if(first.get_day() < second.get_day())
		return true;
	// else
	return false;
}
bool operator>(Date first, Date second) { return second < first; }
bool operator==(Date first, Date second) { return (!(first > second) && !(first < second)); }
bool operator!=(Date first, Date second) { return !(first == second); }
std::ostream& operator<<(std::ostream& os, Date d) { return os << d.get_day() << "/" << d.get_month() << "/" << d.get_year(); }
