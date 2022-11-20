#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Date.h"

class Book
{
public:

	// COSTRUTTORI
	Book(
		std::string name = default_string, 
		std::string surname = default_string, 
		std::string book_title = default_string, 
		std::string isbn = "000-000-000-x",
		Date copyright = default_date,		// assegnamento di copia di date 
		bool availability_status = true
		);

	// costruttore di copia
//	Book (const Book& b);
	// costruttore di spostamento
//	Book (Book&& b);
	// assegnamento di copia
//	Book& operator= (const Book& b);
	// assegnamento di spostamento
//	Book& operator= (Book&& b);

	// getters
	std::string get_isbn();
	std::string get_auth_name();
	std::string get_auth_surname();
	std::string get_title();
	Date get_copyright();
	bool is_available();

	// setters, per scelta non ritornano il dato precedente
	void set_isbn(std::string);	// throws Invalid ISBN code
	void set_auth_name(std::string);
	void set_auth_surname(std::string);
	void set_title(std::string);
	void set_copyright(Date);
	
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
		// costruttore
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
bool operator==(Book b, Book c);
bool operator!=(Book b, Book c);
std::ostream& operator<<(std::ostream& os, Book b);


#endif // BOOK_H