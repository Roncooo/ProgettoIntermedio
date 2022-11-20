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
		Book book_im_reading = Book("Hannah", "Arendt", "La banalita' del male", "888-222-444-r", Date(6, 8, 1997), false);
		cout << "Libro creato: " << book_im_reading << "\n" << endl;
		
		// ritorno book_im_reading
		cout << "*** Processo di restituzione del libro ***\n";
		book_im_reading.return_book();
		cout << "Hai restituito: " << book_im_reading <<"\n" << endl;
		cout << book_im_reading.get_title() << " di " << book_im_reading.get_auth_surname() <<" disponibile per il prestito\n" << endl;
		
		//libro 2
		cout << "Creo e stampo un altro libro" << endl;
		Book bd_book = Book ("Matt", "Fraction", "Fear Itself", "882-871-134-6", Date(1,2,1953));
		cout << bd_book << endl << endl;
		
		// creo e prendo in prestito un libro
		Book book_i_want = Book("Stephen W.", "Hawking", "La teoria del tutto","978-881-707-3", Date(1, 1, 1998));
		cout << "Libro creato: " << book_i_want << "\n" << endl;
		cout << "*** Processo di presa in prestito del libro ***\n";
		
		book_i_want.borrow_book();
		cout << "Hai preso in prestito: " << book_i_want <<"\n" << endl;
		
		// provo a confrontare i libri creati in precedenza
		cout << "Il libro restituito e quello preso in prestito sono uguali?\n";
		if(book_im_reading != book_i_want)
			cout << "I due libri non sono uguali\n";
		else
			cout << "I due libri sono uguali\n";
		
		// creo un altro libro con ISBN di default e confronto con il primo creato
		Book book_prova = Book();
		cout << "Il libro di prova: " << book_prova <<"\n";
		cout << "Il libro di prova e " << last_book_read.get_title() << " sono uguali?\n";
		if(book_prova == last_book_read)
			cout << "I due libri sono uguali\n" << endl;
		else
			cout << "I due libri non sono uguali\n" << endl;
		
		//	dati
		string title = "Una cosa divertente che non faro' mai piu'";
		string name = "David";
		string surname = "Foster Wallace";
		string isbn = "887-521-837-4";
		
		//	COSTRUZIONE DI BOOK, prerequisito del progetto
		Book my_favourite_book (name, surname, title, isbn);
		std::cout << my_favourite_book  << "\n" << std::endl;
		
		//creo un vettore di book
		vector<Book> shelf(10);
		cout << "Vector di Book creato\n";
		//controllo
		for (int i = 0; i < shelf.size(); i++)
			cout << shelf[i] << endl;
			
	}
	catch(Date::InvalidDateException e) { cerr << "***ERRORE***: hai creato una data invalida!\n"; }
	catch(Book::InvalidCopyrightDateException e) { cerr << "***ERRORE***: hai creato una data invalida per il copyright!\n"; }
	catch(Book::ImpossibleToBorrowUnvailableBook e) { cerr << "***ERRORE***: non puoi prendere in prestito un libro non disponibile!\n";}
	catch(Book::ImpossibleToReturnAvailableBook e) { cerr << "***ERRORE***: non puoi ritornare un libro gia' disponibile!\n"; }
	catch(Book::InvalidIsbnException e) {cerr << "***ERRORE***: formato ISBN non valido";}
	
	return 0;
}
