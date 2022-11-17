#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
    //specifico le variabili private della classe Date
    //m è del tipo UDT Month, creato con la enum Month
    
    static constexpr int max_day_feb = 29; //il 29 febbraio mi servirà per il check sul mese febbraio
    static constexpr int next_year = 2023; //un libro non può avere anno di copyright successivo a quello corrente, mi serve per il check
    struct InvalidYearException{};
    enum Month{};
    
    int day;
    int year;
    Month mon;
    
public:
    
    //costruttore, che comprende anche il costruttore di default, throws InvalidYearException() se l'anno è negativo
    //se non specificati i parametri, creo la data "1 Gennaio 2000", vedi file.cpp (è più corretto settarli nel file header?)
    Date(int d, Month m, int y);
    
    //funzioni getter
    int get_day() const { return day; }
    Month get_month() const { return mon; }
    int get_year() { return year; }
    
    //controllo la validità di una data
    bool is_valid_date();
    //controllo se l'anno è bisestile
    bool is_leap_year();
    
    //funzione check febbraio throws FebruaryException()
    bool check_february();

};

//bool is_valid_date(); //la costruisco all'infuori della classe perchè effettivamente lei non opera su un oggetto date
std::ostream& operator<<(std::ostream& os, Date d);

#endif // DATE_H
