// Bellesso Beatrice, Bruzzese Fuvio, Roncolato Francesco

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Date.h"


/* Il costruttore di copia e l'operatore di assegnamento di copia non sono stati scritti poiché
 * per le variabili membro di tipi built-in viene automaticamente fatta una deep-copy e 
 * similmente anche per Date (che invece è UDT) vanno bene le funzioni esistenti di default in quanto
 * le sue variabili membro sono di tipo built-in o riconducibile a tipo built-in (come l'enum Month).
 * Per pignoleria è stato verificato nel tester che avviene correttamente la procedura di copia di default.
 * Il costruttore di spostamento e l'operatore di assegnamento di spostamento non sono stati scritti poiché
 * gli oggetti di tipo Book e di tipo Date hanno dimensione ridotta e fissa (rispettivamente 144 e 12 byte) quindi 
 * anche in questo caso le ottimizzazioni di default del compilatore sono più che sufficienti.
 * L'operatore delete non è stato scritto in quanto non si fa mai uso dell'allocazione dinamica della memoria
 * e tutti i tipi di variabili da noi utilizzati sono automaticamente gestiti
 * */

class Book
{
public:

	// costruttore,		throws InvalidCopyrightDateException, InvalidIsbnException
	Book(
		std::string name = default_string, 
		std::string surname = default_string, 
		std::string book_title = default_string, 
		std::string isbn = "000-000-000-x",
		Date copyright = default_date,		// deve essere una data reale compresa tra il 1952 e il 2022
		bool availability_status = true
		);		

	// getters
	std::string get_isbn();
	std::string get_auth_name();
	std::string get_auth_surname();
	std::string get_title();
	Date get_copyright();
	bool is_available();

	// setters, per scelta non ritornano il dato precedente
	void set_isbn(std::string);		// throws InvalidIsbnException
	void set_auth_name(std::string);
	void set_auth_surname(std::string);
	void set_title(std::string);
	void set_copyright(Date);		// throws InvalidCopyrightDateException
	
	// eccezioni
	struct ImpossibleToBorrowUnvailableBook{};
	struct ImpossibleToReturnAvailableBook{};
	struct InvalidIsbnException{};
	struct InvalidCopyrightDateException{};
	
	// cambiano lo stato di is_available se è ragionevole
	void borrow_book(); 	// throws ImpossibleToBorrowUnvailableBook
	void return_book();		// throws ImpossibleToReturnAvailableBook

private:

	class Isbn
	{
	public:
		Isbn(std::string code);		// throws Invalid ISBN code
		static bool is_valid_isbn(std::string code);
		std::string isbn_str;
	};

	// variabili membro di Book
	Isbn isbn_code;
	std::string title;
	std::string auth_name;
	std::string auth_surname;
	Date copyright_date;
	bool availability;

	// variabili statiche
	static std::string default_string;
	static Date default_date;
	static constexpr int this_year = 2022; // evita un copyright impostato ad un valore futuro
};

// overloading operatori
bool operator==(Book b, Book c);		// confronta solo il codice ISBN
bool operator!=(Book b, Book c);		// confronta solo il codice ISBN
std::ostream& operator<<(std::ostream& os, Book b);


#endif // BOOK_H