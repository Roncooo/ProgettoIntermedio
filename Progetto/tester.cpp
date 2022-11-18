#include <iostream>
#include "Book.h"

#include "Date.h"	// lo esplicito solo perché voglio testare singolarmente Date, in realtà non serve

int main(void)
{
	std::cout << "CIAOO\n";
	//	DATI
	std::string title = "Una cosa divertente che non faro' mai piu'";
	std::string name = "David";
	std::string surname = "Foster Wallace";
	std::string isbn = "887-521-837-4";
	
	//	testo Date
		//	Date d = Date(20,12,1970);						// error: invalid conversion from 'int' to 'Date::Month'
			// è brutto che si debba fare così per forza, ha senso inventarsi un modo per fare la conversione da int a Month?
			Date d = Date(20,Date::Month::dec,2002);		
	std::cout << d << " ok\n";
		//	Date prova = Date(29,Date::Month::feb,2005);	// giustamente lancia invalid date
		//	Date prova = Date(31,Date::Month::apr,2005);	// giustamente lancia invalid date
		//	Date prova = Date(32,Date::Month::jan,2005);	// giustamente lancia invalid date
		//	Date prova = Date(-5,Date::Month::jan,2005);	// giustamente lancia invalid date
		//	Date prova = Date(2,Date::Month::fulvio,2005);	// giustamente lancia 'fulvio' is not a member of Date::Month
//	std::cout << Date::is_valid_date(29,Date::Month::feb,2005) << "\n";


	//	COSTRUZIONE DI BOOK
	Book my_favourite_book (name, surname, title, isbn);
	
	std::cout << my_favourite_book << std::endl;
	
	
	
	return 0;
}