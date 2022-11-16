#include "Book.h"

//Book::Book()
//{
//}
//
//Book::~Book()
//{
//}

// costruttore, throws Invalid ISBN code
Book::Isbn::Isbn(std::string code)
{
	if(is_valid_isbn(code))
		isbn_code = code;
	else
		throw InvalidIsbnException();
} 
	
// nnn-nnn-nnn-x
// x lettera o numero ma non carattere speciale
// ci sono un po' di maginumbers, dite che va bene lo stesso?
bool Book::Isbn::is_valid_isbn(std::string s)
{
	char dlm = '-';
	
	if(s.length()!=13)
		return false;
	
	for(int i=0; i<3; i++)
	{
		if( (!isdigit(s[i])) || (!isdigit(s[i+4])) || (!isdigit(s[i+8])) )
			return false;
	}
	
	if( s[3]!=dlm || s[3+4]!=dlm || s[3+8]!=dlm )
		return false;
	
	char x = s[12];
	if( 
		!(x>=48 && x<=57) && // x is not a number digit
		!(x>=65 && x<=90) && // x is not a capital letter
		!(x>=97 && x<=122)   // x is not a lowercase letter
	  )
		return false;
	
	// else
	return true;
}
