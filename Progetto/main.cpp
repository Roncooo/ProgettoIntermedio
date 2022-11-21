#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

int main(void)
{
	try
	{
		cout << "***** INIZIO TEST DI BOOK *****\n";
		
		cout << "Creazione e stampa di tre libri\n";
		Book my_favourite_book ("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
		cout << my_favourite_book  << "\n";
		Book last_book_read = Book("Adam", "Douglas", "The Hitchhikker's Guide to the Galaxy");
		cout << last_book_read << "\n";
		Book book_im_reading = Book("Hannah", "Arendt", "La banalita' del male", "888-222-444-r", Date(6, 8, 1997), false);
		cout << book_im_reading << "\n\n";
		
		// mettendo una data precedente al 1/1/52 giustamente lancia eccezione
//		Book invalid_date_book = Book("Hannah", "Arendt", "La banalita' del male", "888-222-444-r", Date(6, 8, 1950), false);
		
		cout << "*** Processo di restituzione del libro ***\n";
		book_im_reading.return_book();
		cout << "Hai restituito: " << book_im_reading <<"\n";
		if(book_im_reading.is_available())
			cout << book_im_reading.get_title() << " di " << book_im_reading.get_auth_surname() << " disponibile per il prestito\n\n";
		else
			cout << "Errore: il libro è stato restituito e ora dovrebbe essere dispobile\n";
		
		cout << "*** Processo di presa in prestito del libro ***\n";
		Book book_i_want = Book("Stephen W.", "Hawking", "La teoria del tutto","978-881-707-3", Date(1, 1, 1998));
		book_i_want.borrow_book();
		if(book_i_want.is_available())
			cout << "Errore: il libro è stato preso in prestito e non dovrebbe più essere disponibile";
		else
			cout << "Hai preso in prestito: " << book_i_want << "\n\n";
		
		cout << "*** Confronto tra due libri *** (tra i loro codici isbn)\n";	// come da consegna
		if(book_im_reading != book_i_want)
			cout << "I due libri non sono uguali (" << book_im_reading.get_isbn() << "!=" << book_i_want.get_isbn() << ")\n";
		else
			cout << "I due libri sono uguali\n";
		
		// creo un altro libro con ISBN di default e confronto con il primo creato
		Book default_book = Book();
		cout << "Libro di default: " << default_book <<"\n";
		cout << "Il libro di default e " << last_book_read.get_title();
		if(default_book == last_book_read)
			cout << " sono uguali (" << default_book.get_isbn() << "==" << last_book_read.get_isbn() << ")\n\n";
		else
			cout << " non sono uguali\n\n";
		
		cout << "*** Test dei setters ***\n";
		cout << "Modifico manualmente i campi del libro: \"" << book_im_reading.get_title() << "\"\n";
		book_im_reading.set_title("Discrete Calculus");
		book_im_reading.set_auth_name("Carlo");
		book_im_reading.set_auth_surname("Mariconda");
		book_im_reading.set_isbn("123-456-789-m");
		book_im_reading.set_copyright(Date(5, 7, 2000));
		cout << "Adesso il libro che sto leggendo e': ";
		cout << book_im_reading << "\n\n";
		
		// creo un vettore di book
		cout << "*** Dichiarazione e stampa di un vector<Book> *** \n";
		cout << "\tserve a testare i costruttori di default\n";
		vector<Book> shelf(10);
		for (int i = 0; i < shelf.size(); i++)
			cout << "v[" << i << "] = " << shelf[i] << "\n";
		
		cout << "\n*** Assegnamento di copia per Book***\n";
		Book copy_book("Nome", "Cognome", "Titolo", "123-123-123-a", Date(25,9,1989), false);
		my_favourite_book = copy_book;
		cout << "Il libro sovrascritto e' ora: " << my_favourite_book << "\n";
		copy_book.set_isbn("987-654-231-x");
		cout << (copy_book == my_favourite_book ? "E' stata fatta una shallow copy" : "E' stata fatta una deep copy\n\n");
		
		cout << "*** Costruttore di copia per Book ***\n";
		Book constr_book = copy_book;
		cout << "Il libro costruito per copia e': " << constr_book << "\n";
		copy_book.set_isbn("000-000-000-x");
		cout << (copy_book == constr_book ? "E' stata fatta una shallow copy" : "E' stata fatta una deep copy\n");
		
		
		cout << "\n\n***** INIZIO TEST DI DATE *****\n";
		cout << "Creo delle date:";
		Date d1 = Date(20,12,1970);
		Date d2 = Date(20,Date::Month::dec,2002);
		// creando queste giustamente viene lanciata InvalidDateException
//		Date invalid_date_1 = Date(29,Date::Month::feb,2005);	// invalida: non esiste il 29 febbraio
//		Date invalid_date_2 = Date(31,Date::Month::apr,2005);	// invalida: non esiste il 31 aprile
//		Date invalid_date_3 = Date(32,Date::Month::jan,2005);	// invalida: non esiste il 32 gennaio
//		Date invalid_date_4 = Date(-5,Date::Month::jan,2005);	// invalida: non esiste il giorno -5
		cout << "La data d1 e': "<< d1 << ", ok!\n";
		cout << "La data d2 e': "<< d2 << ", ok!\n";
		cout << (d1<d2 ? "d1 viene prima di d2\n" : "d1 viene dopo d2");
		cout << (Date::is_valid_date(29,2,2005) ? "Il 29/2/2005 esiste" : "Il 29/2/2005 non esiste\n");
		cout << (Date::is_leap_year(2004) ? "Il 2004 e' bisestile\n" : "Il 2004 non è bisestile");
		
	}
	catch(Date::InvalidDateException e) { cerr << "***ERRORE***: hai creato una data invalida!\n"; }
	catch(Book::InvalidCopyrightDateException e) { cerr << "***ERRORE***: hai creato una data invalida per il copyright!\n"; }
	catch(Book::ImpossibleToBorrowUnvailableBook e) { cerr << "***ERRORE***: non puoi prendere in prestito un libro non disponibile!\n";}
	catch(Book::ImpossibleToReturnAvailableBook e) { cerr << "***ERRORE***: non puoi ritornare un libro gia' disponibile!\n"; }
	catch(Book::InvalidIsbnException e) {cerr << "***ERRORE***: formato ISBN non valido";}
	
	return 0;
}
