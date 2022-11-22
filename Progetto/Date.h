// Bellesso Beatrice, Bruzzese Fuvio, Roncolato Francesco

#ifndef DATE_H
#define DATE_H

#include <iostream>

/* Il costruttore di copia e l'operatore di assegnamento di copia non sono stati scritti poiché
 * per le variabili membro di tipi built-in viene automaticamente fatta una deep-copy. Questo vale anche per
 * l'enum Month in quanto viene ricondotto ad un tipo built-in.
 * Il costruttore di spostamento e l'operatore di assegnamento di spostamento non sono stati scritti poiché
 * gli oggetti di tipo Date hanno dimensione ridotta e fissa (12 byte) quindi anche in questo caso le ottimizzazioni 
 * di default del compilatore sono più che sufficienti.
 * L'operatore delete non è stato scritto in quanto non si fa mai uso dell'allocazione dinamica della memoria
 * e tutti i tipi di variabili da noi utilizzati sono automaticamente gestiti
 * */

class Date
{
public:
	
	enum Month
    {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
	
	// costruttore con argomenti di default "1 Gennaio 1970"
	Date(int d = 1, Month m = jan, int y = 1970);	// throws InvalidDateException
	
	// costruttore che prende anche il mese passato per intero
	Date(int d, int m, int y);						// throws InvalidDateException
	
	//eccezione
	struct InvalidDateException{};
	
	// getters
	int get_day() const { return day; }
	Month get_month() const { return mon; }
	int get_year() const { return year; }
	
	// funzioni membro statiche, non agiscono su un oggetto
	static bool is_valid_date(int d, Date::Month m, int y);
	static bool is_valid_date(int d, int m, int y);
	static bool is_leap_year(int y);
	
private:
	
	int day;
	int year;
	Month mon;
	
	// servira' per il check sul mese febbraio
	static constexpr int max_day_feb = 29; 
};

// overloading operatori
bool operator<(Date first, Date second);
bool operator>(Date first, Date second);
bool operator==(Date first, Date second);
bool operator!=(Date first, Date second);
std::ostream& operator<<(std::ostream& os, Date d);

#endif // DATE_H