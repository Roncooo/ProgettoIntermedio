#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "Date.h"

class Book
{
public:
		
	// COSTRUTTORI
	// con tutti i parametri
	// 
	// Book my_favourite_book(“David”, “Foster Wallace”, “Una cosa divertente che non farò mai più”, “887-521-837-4”);
	Book(	std::string name, std::string surname, 
			std::string book_title, 
			std::string isbn, 
			Date copyright, 
			bool availability_status = true);	// argomento di default, per ora metto solo questo ma dobbiamo pensare agli altri
                                                //è availibility non availability_status(?)
	// getters
	std::string get_isbn();			// possiamo far uscire Isbn? secondo me no
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
		
	// variabile
	Isbn isbn_code;
	std::string title;
	std::string auth_name;
	std::string auth_surname;
	Date copyright_date;
	bool availability;
		
	// eccezioni di Book, le mettiamo struct?
	class ImpossibleToBorrowUnvailableBook{};
	class ImpossibleToReturnAvailableBook{};
	class InvalidIsbnException{};
	
};

// helper function
bool is_valid_isbn(std::string code);

// Ghidoni le ha messe fuori
bool operator==(Book b, Book c);
bool operator!=(Book b, Book c);
std::ostream& operator<<(std::ostream& os, Book b); 

#endif // BOOK_HPP
