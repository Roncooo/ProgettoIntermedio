#include "Book.h"

// è brutto secondo voi mettere i parametri così?
//non è bellissimo, ma è più chiaro e l'ho visto fare anche a giulio lol


Book::Book(	
    std::string name,
	std::string surname, 
	std::string book_title, 
	std::string isbn, 
	Date copyright, 
	bool availability_status
    )
	// costruttore con initializer list così non abbiamo problemi di costruttore di default
	:
		isbn_code{Isbn(isbn)},
		title{book_title},
		auth_name{name},
		auth_surname{surname},
		copyright_date{copyright},
		availability{availability_status}
	{ 
		// constructor body, intentionally left blank
	}
//Book::~Book()
//{
//}

//costruttore di copia
Book::Book(const Book& b)
	:
		isbn_code {b.isbn_code},
		title {b.title},
		auth_name {b.name},
		auth_surname {b.auth_surname},
		copyright_date {b.copyright_date}
		availability {b.availability}
	{
	}

//costruttore di spostamento
Book::Book(Book&& b)
	:
		isbn_code {b.isbn_code},
		title {b.title},
		auth_name {b.name},
		auth_surname {b.auth_surname},
		copyright_date {b.copyright_date}
		availability {b.availability}
	{
		b.isbn_code = Isbn("000-000-000-x");
		b.title = default_string;
		b.auth_name = default_string;
		b.auth_surname = default_string;
		b.copyright_date = Date();
		b.availability = true;
	}


//assegnamento di copia
Book& Book::operator= (const Book& b)
{
	isbn_code = b.isbn_code;
	title = b.title;
	auth_name = b.auth_name;
	auth_surname = b.auth_surname;
	copyright_date = b.copyright_date;
	availability = b.availability;
	return *this;
}

//assegnamento di spostamento
Book& Book::operator= (Book&& b)
{
	isbn_code = b.isbn_code;
	title = b.title;
	auth_name = b.auth_name;
	auth_surname = b.auth_surname;
	copyright_date = b.copyright_date;
	availability = b.availability;
	
	b.isbn_code = Isbn("000-000-000-x");
	b.title = default_string;
	b.auth_name = default_string;
	b.auth_surname = default_string;
	b.copyright_date = Date();
	b.availability = true;
	
	return *this;
}


// getters
std::string Book::get_isbn() { return isbn_code.isbn_str; }
std::string Book::get_auth_name() { return auth_name; }
std::string Book::get_auth_surname() { return auth_surname; }
std::string Book::get_title() { return title; }
Date Book::get_copyright() { return copyright_date; }
bool Book::is_available() { return availability; }

// cambiano lo stato di is_available se ha senso
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


// costruttore, throws Invalid ISBN code
Book::Isbn::Isbn(std::string code)
{
	if(is_valid_isbn(code))
		isbn_str = code;
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
	
	char last = s[12];
	// controllo il numero progressivo del carattere nella tabella ascii
	if( 
		!(isdigit(last)) && 		// last is not a number digit
		!(last>=65 && last<=90) &&  // last is not a capital letter
		!(last>=97 && last<=122)    // last is not a lowercase letter
	  )
		return false;
	
	// else
	return true;
}


// *** OVERLOADING OPERATORI ***

bool operator==(Book b, Book c)
{
	return b.get_isbn() == c.get_isbn();
}

bool operator!=(Book b, Book c)
{
	return b.get_isbn() != c.get_isbn();
}

std::ostream& operator<<(std::ostream& os, Book b)
{
	std::string sep = ", ";
	return os << b.get_auth_name() + sep + b.get_auth_surname() + sep +
				b.get_title() + sep + b.get_isbn() + sep << b.get_copyright(); 
}