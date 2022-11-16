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
    
    struct InvalidYearException{};
    
public:
    
    //costruttore, che comprende anche il costruttore di default
    //se non specificati i parametri, creo la data "1 Gennaio 2000", vedi file.cpp (è più corretto settarli nel file header?)
    Date(int d, Month m, int y);
    
    //l'anno è bisestile? un anno è bisestile se 1) è divisibile per 4 2)un anno divisibile per 100 è bisestile se divisibile per 400
    bool is_bisestile();
    
    
    
    
    ~Date();

};

#endif // DATE_H
