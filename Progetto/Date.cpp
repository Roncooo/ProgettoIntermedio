#include "Date.h"
// secondo me è meglio fare una funzione bool is_valid_date(int d, int m, int y) pubblica, così l'utente può usarla per evitare di creare date che lanciano eccezioni
// dentro is_valid_date
	// controllo generico dei dati 0<mese<=12, 0<giorno<=31 
	// 0<=anno<=2023 (?? è una scelta, per me ci sta)
	// controllo dei giorni del mese (che delegherei ad un'altra funzione magari check_month_days(gg,mm) helper)
		// se il mese è gennaio devo avere il giorno <=31
		// se il mese è febbraio devo invocare anche is_leap_year(yyyy)
		// se il mese è marzo ... tutte queste if magari con una switch
// nel costruttore if(!is_valid_date) throw new InvalidDateException();

	
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

// io la metterei helper function che prende un intero
//io no, ha senso che la funzioni acceda alla mia istanza
//io non capisco il senso del primo if, cioè secondo me dovrebbe essere:
//if((this->year % 100 == 0) && (this->year % 400 != 0)) 
//     return false
bool Date::is_leap_year(int y)
{
	if((y % 100 == 0) && (y % 400 != 0)) //se un anno è divisibile per 100 e per 400 è bisestile
		return false;
	
	if(y % 4 == 0) //se un anno è divisibile per 4 è bisestile
		return true;
	
	return false;
}


std::ostream& operator<<(std::ostream& os, Date d)
{
	return os<<d.get_day()<<"/ "<<d.get_month()<<"/ "<<d.get_year()<<"\n"; 
}

bool Date::is_valid_date(int d, Month m, int y)
{
	if(y > next_year || y < 0)
		return false;
	else if(m < 1 || m > 12)
		return false;
	else if(d < 0 || d > 31)
		return false;
	
	//ora devo fare i controlli sui vari mesi
	if( (is_leap_year(y)) && (m == feb) ) //febbraio 
	{
		if(d > max_day_feb) //domanda: i magic number sono brutti, ma in questo caso quindi è meglio fare tante variabili constexpr? 
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
        return true;
    }
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
