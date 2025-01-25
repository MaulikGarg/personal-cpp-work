/*
5] This exercise and the next few require you to design and implement a Book class, such as you
can imagine as part of software for a library. Class Book should have members for the ISBN,
title, author, and copyright date. Also store data on whether or not the book is checked out.
Create functions for returning those data values. Create functions for checking a book in and out. 
Do simple validation of data entered into a Book; for example, accept ISBNs only of the
form n−n−n−x where n is an integer and x is a digit or a letter. Store an ISBN as a string

6] Add operators for the Book class. Have the == operator check whether the ISBN numbers are
the same for two books. Have != also compare the ISBN numbers. Have a << print out the
title, author, and ISBN on separate lines.
*/

#include "date.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    return os << date.getYear().value << "-"
              << static_cast<int>(date.getMonth()) << "-"
              << date.getDay();
}

// main book class for initializing and getting information about a book, (isbn, title, author, date, availability)
class Book
{
private:
    // a unique identity number in format int-int-int-char
    string isbnNumber;
    // title of the book
    string title;
    // author's own name
    string authorName;
    // last copyright check date
    Date copyright;
    // if the book is available in the library
    bool isAvailable;

public:
    // constructor getting the necessary information, also checks if input string is valid isbn.
    Book(string inputisbn, string inputTitle, string inputAuthor, Date inputDate, bool inputAvailability)
        : isbnNumber{inputisbn},
          title{inputTitle},
          authorName{inputAuthor},
          copyright{inputDate},
          isAvailable{inputAvailability}
    {
        if (!isvalidISBN(inputisbn))
        {
            exit(1);
        };
    }
    //function prototype, checks if an input ISBN number is valid or not
    bool isvalidISBN(const string &inputisbn);

    //overloaded operators to check whether the books are equal or not, just compares their ISBN
    bool operator==(const Book& comapredBook);
    bool operator!=(const Book& comapredBook);
};

// checks if the input isbn is in format int-int-int-char, where each int is 3 digits
bool Book::isvalidISBN(const string &inputisbn)
{

    // check length
    if (inputisbn.length() != 13)
        return false;

    // check the isbn itself
    for (int i = 0; i < 13; i++)
    {
        // at hyphen position, check for it and continue loop by 2
        if (i == 3 || i == 7 || i == 11)
        {
            if (inputisbn[i] != '-')
                return false;
        }
        //at last position, check if it is a letter or digit
        else if (i == 12)
        {
            // check for char
            if (!isalpha(inputisbn[12]) && !isdigit(inputisbn[12]))
                return false;
        }
        else
        {
            if (!isdigit(inputisbn[i]))
                return false;
        }
    }

    // all checks passed, its a valid isbn
    return true;
}

//== and!= overloads checking if the ISBN NUMBERS are equal or not
bool Book::operator==(const Book& comapredBook){
    if(isbnNumber == comapredBook.isbnNumber) return true;
    return false;
}
bool Book::operator!=(const Book& comapredBook){
    if(isbnNumber != comapredBook.isbnNumber) return true;
    return false;
}

int main()
{
    Book b1("123-456-789-x","my book","me", Date{Year{2005}, Month::sep, 4}, true);
    cout << 0;
    return 0;
}
