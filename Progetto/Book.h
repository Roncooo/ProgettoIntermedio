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
	Book(	
		std::string name = default_string, 
		std::string surname = default_string, 
		std::string book_title = default_string, 
		std::string isbn = "000-000-000-x", 
		Date copyright, // teoricamente basta a chiamare il costruttore di default di date 
		bool availability_status = true);	// argomento di default, per ora metto solo questo ma dobbiamo pensare agli altri
                                               
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
	
	class Isbn
	{
	public:
		Isbn(std::string code); // throws Invalid ISBN code
		static bool is_valid_isbn(std::string code);
			// non ha senso che venga chiamato su un oggetto Isbn, meglio se prende una stringa e controlla quella
			// quindi è "statico"
			// nnn-nnn-nnn-x  con x lettera o numero ma non carattere speciale
		// variabile membro
		std::string isbn_str;

		// è giusto dichiararla qui? o meglio fuori da isbn?
		// e perché non struct?
		class InvalidIsbnException{};
	};


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
	
	static std::string default_string = "Not_specified";
};


// Ghidoni le ha messe fuori
bool operator==(Book b, Book c);
bool operator!=(Book b, Book c);
std::ostream& operator<<(std::ostream& os, Book b); 

#endif // BOOK_HPP
