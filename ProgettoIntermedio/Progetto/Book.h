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
		Date copyright = default_date,	// assegnamento di copia di date 
		bool availability_status = true
		);
	
	// costruttore di copia
	Book (const Book& b);
	// costruttore di spostamento
	Book (Book&& b);
	// assegnamento di copia
	Book& operator= (const Book& b);
	// assegnamento di spostamento
	Book& operator= (Book&& b);

	
	// getters
	std::string get_isbn();
	std::string get_auth_name();
	std::string get_auth_surname();
	std::string get_title();
	Date get_copyright();
	bool is_available();

	// cambiano lo stato di is_available se ha senso
	void borrow_book(); 	// throws ImpossibleToBorrowUnvailableBook
	void return_book();		// throws ImpossibleToReturnAvailableBook
		
// Ghidoni in Rational non mette il distruttore
//	~Book();
private:
	
	class Isbn
	{
	public:
		
		Isbn(std::string code); // throws Invalid ISBN code
		
		static bool is_valid_isbn(std::string code);
		
		// variabile membro
		std::string isbn_str;

		// eccezione
		struct InvalidIsbnException{};
	};


	// variabile
	Isbn isbn_code;
	std::string title;
	std::string auth_name;
	std::string auth_surname;
	Date copyright_date;
	bool availability;
	
	// eccezioni
	struct ImpossibleToBorrowUnvailableBook{};
	struct ImpossibleToReturnAvailableBook{};
	
	// variabili statiche
	static std::string default_string;
	static Date default_date;
};

// dichiarazioni ***OVERLOADING OPERATORI***
bool operator==(Book b, Book c);
bool operator!=(Book b, Book c);
std::ostream& operator<<(std::ostream& os, Book b);


#endif // BOOK_H
