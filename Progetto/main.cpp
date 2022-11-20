#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

int main(void)
{
	try
	{
		cout << "**INIZIO TEST DI DATE**\n";
		cout << "Creo delle date:\n";
		Date d1 = Date(20,12,1970);
		Date d2 = Date(20,Date::Month::dec,2002);
//		creando queste giustamente viene lanciata InvalidDateException
//		Date prova1 = Date(29,Date::Month::feb,2005);	// invalida: non esiste il 29 febbraio
//		Date prova2 = Date(31,Date::Month::apr,2005);	// invalida: non esiste il 31 aprile
//		Date prova3 = Date(32,Date::Month::jan,2005);	// invalida: non esiste il 32 gennaio
//		Date prova4 = Date(-5,Date::Month::jan,2005);	// invalida: non esiste il giorno -5
		
		cout << "La data d1 e': "<< d1 << ", ok!\n";
		cout << "La data d2 e': "<< d2 << ", ok!\n";
		
		cout << "\n**INIZIO TEST DI BOOK**\n";
		cout << "Creo e stampo un libro\n";
		Book last_book_read = Book("Adam", "Douglas", "The Hitchhikker's Guide to the Galaxy");
		cout << last_book_read << "\n";
		// mettendo una data precedente al 1/1/52 giustamente lancia eccezione
		Book book_im_reading = Book("Hannah", "Arendt", "La banalita' del male", "888-222-444-r", (1,2,3), true);
		cout << book_im_reading << "\n";
		// prendo in prestito book_im_reading
		book_im_reading.borrow_book();
		if(book_im_reading.is_available())
			cout << "Libro disponibile per il prestito\n";
		else
			cout << "Libro non disponibile per il prestito\n";
			
			
		//	dati
		string title = "Una cosa divertente che non faro' mai piu'";
		string name = "David";
		string surname = "Foster Wallace";
		string isbn = "887-521-837-4";
		//	COSTRUZIONE DI BOOK
		Book my_favourite_book (name, surname, title, isbn);
		
		std::cout << my_favourite_book  << "\n" << std::endl;
			
	}
	catch(Date::InvalidDateException e) { cerr<<"Hai creato una data invalida!\n"; }
	catch(Book::InvalidCopyrightDateException e) { cerr<<"Hai creato una data invalida per il copyright!\n"; }

	
	// creo un vector di book con i costruttori di default 
	std::vector<Book> shelf(10);
	
	return 0;
}
