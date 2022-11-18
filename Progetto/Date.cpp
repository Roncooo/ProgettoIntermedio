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
enum Date::Month
{
	jan = 1, feb, mar, june, july, aug, sept, oct, nov, dec 
}
	
Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
	if(y < 0)
		throw new InvalidYearException();
	
}

// io la metterei helper function che prende un intero
//io no, ha senso che la funzioni acceda alla mia istanza
//io non capisco il senso del primo if, cioè secondo me dovrebbe essere:
//if((this->year % 100 == 0) && (this->year % 400 != 0)) 
//     return false
bool Date::is_leap_year()
{
	if((this->year % 100 == 0) && (this->year % 400 == 0)) //se un anno è divisibile per 100 e per 400 è bisestile
		return true;
	else if(this->year % 4 == 0) //se un anno è divisibile per 4 è bisestile
		return true;
	return false;
}


std::ostream& Date::operator<<(std::ostream& os, Date d)
{
	return os<<d.get_day()<<"/ "<<d.get_month()<<"/ "<<d.get_year()<<"\n"; 
}

bool Date::is_valid_date()
{
	if(this->year > next_year || this-> year < 0)
		return false;
	else if(this->mon < 1 || this->mon > 12)
		return false;
	else if(this->day < 0 || this->day > 31)
		return false;
	
	//ora devo fare i controlli sui vari mesi
	if(this->is_leap_year() && this->mon == feb) //febbraio 
	{
		if(this->day > max_day_feb) //domanda: i magic number sono brutti, ma in questo caso quindi è meglio fare tante variabili constexpr? 
		{
			return false;
		}
		return true;
	}
	else if((this->mon == feb) && (!this->is_leap_year()))
	{
		if(this->day > 28)
			return false;
		return true;
	}
	//non la implemento con una switch perché il modo in cui gestisco i casi particolari è lo stesso, altrimenti avrei un codice ripetitivo
	if(this->mon == apr || this->mon == june || this->mon == sept || this->mon == nov)
	   {
		   if(this->day > 30)
		   {
			return false;
		   }
		   return true;
	   }
}
