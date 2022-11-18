#include <iostream>
#include "Book.h"

int main(int argc, char **argv)
{
//	DATI
	std::string title = "Una cosa divertente che non farò mai più";
	std::string name = "David";
	std::string surname = "Foster Wallace";
	std::string isbn = "887-521-837-4";
	
//	COSTRUZIONE DI BOOK
	Book my_favourite_book (name, surname, title, isbn);
	
	std::cout << my_favourite_book << std::endl;
	
	
	
	return 0;
}