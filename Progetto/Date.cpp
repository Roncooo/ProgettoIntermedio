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

Date::Date(int d = 1, Month m = jan, int y = 2000):day{d}, mon{m}, year{y}
{
    if(y < 0)
        throw new InvalidYearException();
    
}

// io la metterei helper function che prende un intero
bool Date::is_leap_year()
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

std::ostream& Date::operator<<(std::ostream& os, Date d)
{
    return os<<d.get_day()<<"/ "<<d.get_month()<<"/ "<<d.get_year()<<"\n"; 
}


