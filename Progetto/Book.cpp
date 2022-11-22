// Bellesso Beatrice, Bruzzese Fuvio, Roncolato Francesco

#include "Book.h"

std::string Book::default_string = "Not_specified";
Date Book::default_date = Date(1,1,1952);	// scelta come data di riferimento perché il copyright scade dopo 70 anni

// costruttore
Book::Book(
    std::string name,
	std::string surname, 
	std::string book_title, 
	std::string isbn, 
	Date copyright, 
	bool availability_status
    )
	:
		isbn_code{Isbn(isbn)},
		title{book_title},
		auth_name{name},
		auth_surname{surname},
		copyright_date{copyright},
		availability{availability_status}
	{ 
		if((copyright.get_year() > this_year) || (copyright < default_date))
		{
			throw InvalidCopyrightDateException();
		}
	}


// getters
std::string Book::get_isbn() { return isbn_code.isbn_str; }
std::string Book::get_auth_name() { return auth_name; }
std::string Book::get_auth_surname() { return auth_surname; }
std::string Book::get_title() { return title; }
Date Book::get_copyright() { return copyright_date; }
bool Book::is_available() { return availability; }

// setters
void Book::set_isbn(std::string s) { isbn_code = Isbn(s); }
void Book::set_auth_name(std::string s) { auth_name = s; }
void Book::set_auth_surname(std::string s) { auth_surname = s; }
void Book::set_title(std::string s) { title = s; }
void Book::set_copyright(Date d)	// throws InvalidCopyrightDateException
{ 
	if((d.get_year() > this_year) || (d < default_date))
		throw InvalidCopyrightDateException();
	copyright_date = d; 
}


void Book::borrow_book()
{
	if(this->is_available())
		availability = false;
	else
		throw ImpossibleToBorrowUnvailableBook();
}

void Book::return_book()
{
	if(!(this->is_available()))
		availability = true;
	else
		throw ImpossibleToReturnAvailableBook();
}


// costruttore di ISBN
Book::Isbn::Isbn(std::string code)
{
	if(is_valid_isbn(code))
		isbn_str = code;
	else
		throw InvalidIsbnException();
} 

// valid format: nnn-nnn-nnn-x
bool Book::Isbn::is_valid_isbn(std::string s)
{
	char dlm = '-';
	if(s.length()!=13)
		return false;
	for(int i=0; i<3; i++)
	{
		if((!isdigit(s[i])) || (!isdigit(s[i+4])) || (!isdigit(s[i+8])))
			return false;
	}
	if(s[3]!=dlm || s[3+4]!=dlm || s[3+8]!=dlm)
		return false;
	char last = s[12];
	// controllo la posizione del carattere nella tabella ascii
	if	( 
			!(isdigit(last)) 		&&	// last is not a number digit
			!(last>=65 && last<=90) &&	// last is not a capital letter
			!(last>=97 && last<=122)	// last is not a lowercase letter
		)
		return false;
	// else
	return true;
}


// overloading operatori
bool operator==(Book b, Book c) { return b.get_isbn() == c.get_isbn(); }
bool operator!=(Book b, Book c) { return b.get_isbn() != c.get_isbn(); }

std::ostream& operator<<(std::ostream& os, Book b)
{
	std::string availability_string = b.is_available() ? "available" : "not available";
	std::string sep = ", ";
	return os << b.get_auth_name() + sep + b.get_auth_surname() + sep +
				b.get_title() + sep + b.get_isbn() + sep << b.get_copyright() << sep + availability_string; 
}