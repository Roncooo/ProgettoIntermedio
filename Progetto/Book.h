#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "Date.h"

class Book
{
public:
		
		// COSTRUTTORI
		// con tutti i parametri
		
		
		// getters

		// cambiano lo stato di is_available se ha senso
		void borrow_book(); 	// throws ImpossibleToBorrowUnvailableBook
		void return_book();		// throws ImpossibleToReturnAvailableBook
		
		

// Ghidoni in Rational non mette il distruttore	
//	~Book();
private:
		
		class Isbn
		{
				Isbn(std::string code); // throws Invalid ISBN code
				bool is_valid();
						// nnn-nnn-nnn-c
						// c lettera o numero ma non carattere speciale
		};
		
		
		// variabile
		Isbn isbn_code;
		std::string title;
		std::string auth_name;
		std::string auth_surname;
		Date copyright;
		bool availability;
		
};

// helper function

// Ghidoni le ha messe fuori
bool operator==(Book b, Book c);
bool operator!=(Book b, Book c);
&ostream operator<<(Book b); 

#endif // BOOK_HPP
