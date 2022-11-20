#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "**INIZIO TEST DI BOOK**\n";
	//	DATI
	string title = "Una cosa divertente che non faro' mai piu'";
	string name = "David";
	string surname = "Foster Wallace";
	string isbn = "887-521-837-4";
	
	//	testo Date
	cout << "Creo due date, una passando un tipo Month(d1) e una un int(d2) per mese:\n";
	Date d1 = Date(20,12,1970);
	Date d2 = Date(20,Date::Month::dec,2002);
	cout << "La data d1 e': "<< d1 << ", ok!\n";
	cout << "La data d2 e': "<< d2 << ", ok!\n";
	// testo una Date invalida
	cout << "Creo 6 date:\n";
	try
	{
		Date d1 = Date(20,12,1970);
		Date d2 = Date(20,Date::Month::dec,2002);
		Date prova1 = Date(29,Date::Month::feb,2005);	// invalida: non esiste il 29 febbraio
		Date prova3 = Date(31,Date::Month::apr,2005);	// invalida: non esiste il 31 aprile
		Date prova4 = Date(32,Date::Month::jan,2005);	// invalida: non esiste il 32 gennaio
		Date prova5 = Date(-5,Date::Month::jan,2005);	// invalida: non esiste il giorno -5
		Date prova6 = Date(2,Date::Month::Bjarne Stroustrup,2005);	//invalida: non esiste il mese Bjarne Stroustrup
		
		cout << "La data d1 e': "<< d1 << ", ok!\n";
		cout << "La data d2 e': "<< d2 << ", ok!\n";
		cout << "La data prova1 e': "<< prova1 << ", ok!\n";
		cout << "La data prova2 e': "<< prova2 << ", ok!\n";
		cout << "La data prova3 e': "<< prova3 << ", ok!\n";
		cout << "La data prova4 e': "<< prova4 << ", ok!\n";
		cout << "La data prova5 e': "<< prova5 << ", ok!\n";
		cout << "La data prova6 e': "<< prova6 << ", ok!\n";
	}
	catch(Date::InvalidDateException())
	{
		cout<<"Hai creato una data non valida!";
	}
		//	Date prova = Date(29,Date::Month::feb,2005);	// giustamente lancia invalid date
		//	Date prova = Date(31,Date::Month::apr,2005);	// giustamente lancia invalid date
		//	Date prova = Date(32,Date::Month::jan,2005);	// giustamente lancia invalid date
		//	Date prova = Date(-5,Date::Month::jan,2005);	// giustamente lancia invalid date
		//	Date prova = Date(2,Date::Month::fulvio,2005);	// giustamente lancia 'fulvio' is not a member of Date::Month
		//	std::cout << Date::is_valid_date(29,Date::Month::feb,2005);

	//	COSTRUZIONE DI BOOK
	Book my_favourite_book (name, surname, title, isbn);
	
	std::cout << my_favourite_book << std::endl;
	
	// creo un vector di book con i costruttori di default 
	std::vector<Book> shelf(10);
	
	return 0;
}
