#ifndef DATE_H
#define DATE_H
#include "Month.h"  // la lasciamo esterna?
#include <iostream>

class Date
{
private:
    //specifico le variabili private della classe Date
    //m è del tipo UDT Month, creato con la enum Month
    int day;
    int year;
    Month mon;
    
    static constexpr int max_day_feb = 29; //il 29 febbraio mi servirà per il check sul mese febbraio
    struct InvalidYearException{};
    struct FebruaryException{};
    
public:
    
    //costruttore, che comprende anche il costruttore di default, throws InvalidYearException() se l'anno è negativo
    //se non specificati i parametri, creo la data "1 Gennaio 2000", vedi file.cpp (è più corretto settarli nel file header?)
    Date(int d, Month m, int y);
    
    //funzioni getter
    int get_day() const { return day; }
    Month get_month() const { return mon; }
    int get_year() { return year; }
    
    //controllo se l'anno è bisestile
    bool is_leap_year();
    
    //funzione check febbraio throws FebruaryException()
    bool check_february();

};

std::ostream& operator<<(std::ostream& os, Date d);

#endif // DATE_H
