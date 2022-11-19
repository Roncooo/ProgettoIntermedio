#include <iostream>
#include "Book.h"

int main(int argc, char **argv)
{
	std::cout << "CIAOO\n";
	//	DATI
	std::string title = "Una cosa divertente che non faro' mai piu'";
	std::string name = "David";
	std::string surname = "Foster Wallace";
	std::string isbn = "887-521-837-4";
	
	//	testo Date
		Date d1 = Date(20,12,1970);
		Date d2 = Date(20,Date::Month::dec,2002);
	std::cout << d1 << " ok\n";
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
