#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
	
	enum Month
    {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
	
	// costruttore con argomenti di default "1 Gennaio 1970"
	Date(int d = 1, Month m = jan, int y = 1970);	// throws InvalidDateException code
	
	// costruttore che prende anche il mese passato per intero
	Date(int d, int m, int y);
	
	// costruttore di spostamento
	Date(Date&& d);
	// assegnamento di spostamento
	Date& operator=(Date&& d);
	// costruttore di copia
	Date(const Date&);
	// assegnamento di copia
	Date& operator=(const Date& d);
	
	// getters
	int get_day() const { return day; }
	Month get_month() const { return mon; }
	int get_year() const { return year; }
	
	static bool is_valid_date(int d, Date::Month m, int y);
	static bool is_leap_year(int y);
	
private:
	
	int day;
	int year;
	Month mon;
	
	static constexpr int max_day_feb = 29; // il 29 febbraio mi servirà per il check sul mese febbraio
	static constexpr int next_year = 2023; // un libro non può avere anno di copyright successivo a quello corrente, mi serve per il check
	
	struct InvalidDateException{};
};

// overloading operatori
bool operator<(Date first, Date second);
bool operator>(Date first, Date second);
bool operator==(Date first, Date second);
bool operator!=(Date first, Date second);
std::ostream& operator<<(std::ostream& os, Date d);


#endif // DATE_H