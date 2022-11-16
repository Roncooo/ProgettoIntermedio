#ifndef DATE_H
#define DATE_H
#include "Month.h"

class Date
{
private:
    //specifico le variabili private della classe Date
    //m è del tipo UDT Month, creato con la enum Month
    int day;
    int year;
    Month mon;
    
    static constexpr int first_copyright_year = 1950; //prima di settanta anni fa non persiste il diritto di copyright
    static constexpr int current_year = 2022; //il limite "superiore" è l'anno corrente, non esiste ancora una data di copyright "2023"
    
    struct InvalidYearException{};
    
public:
    //costruttore, che comprende anche il costruttore di default
    //se non specificati i parametri, creo la data "1 Gennaio 2000", vedi file.cpp (è più corretto settarli nel file header?)
    Date(int d, Month m, int y);
    
    
    
    
    ~Date();

};

#endif // DATE_H
