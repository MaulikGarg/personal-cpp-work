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

7] Create an enumerated type for the Book class called Genre. Hav e the types be fiction, nonfiction,
periodical, biography, and children. Give each book a Genre and make appropriate changes to the
Book constructor and member functions

8] Create a Patron class for the library. The class will have a user’s name, library card number,
and library fees (if owed). Have functions that access this data, as well as a function to set
the fee of the user. Hav e a helper function that returns a Boolean (bool) depending on
whether or not the user owes a fee.

9] Create a Library class. Include vectors of Books and Patrons. Include a struct called Transaction to
record when a book is checked out. Have it include a Book, a Patron, and a Date.
Make a vector of Transactions to keep a record of which books are out. Create functions to
add books to the library, add patrons to the library, and check out books. Whenever a user
checks out a book, have the library make sure that both the user and the book are in the
library. If they aren’t, report an error. Then check to make sure that the user owes no fees. If
the user does, report an error. If not, create a Transaction, and place it in the vector of Transactions.
Also write a function that will return a vector that contains the names of all Patrons
who owe fees.

10] Implement leapyear(int).

11] Design and implement a set of useful helper functions for the Date class with functions such
as next_workday() (assume that any day that is not a Saturday or a Sunday is a workday) and
week_of_year() (assume that week 1 is the week with January 1 in it and that the first day of a
week is a Sunday).

*/

#include "date.cpp" //including this instead of header for quick exercise attempts
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// enumerated class Genre used by book class to identify and list about a book's genre
enum class Genre
{
    fiction,
    nonFiction,
    periodical,
    biography,
    children
};

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
    // a book's genre, taken from the enum type
    Genre genre;

public:
    // constructor getting the necessary information, also checks if input string is valid isbn.
    Book(string inputisbn, string inputTitle, string inputAuthor, Date inputDate, bool inputAvailability, Genre inputGenre)
        : isbnNumber{inputisbn},
          title{inputTitle},
          authorName{inputAuthor},
          copyright{inputDate},
          isAvailable{inputAvailability},
          genre{inputGenre}
    {
        if (!isvalidISBN(inputisbn))
        {
            exit(1);
        };
    }
    // function prototype, checks if an input ISBN number is valid or not
    bool isvalidISBN(const string &inputisbn);

    // overloaded operators to check whether the books are equal or not, just compares their ISBN
    bool operator==(const Book &comapredBook);
    bool operator!=(const Book &comapredBook);

    // output operator overload, prints the information on seperate lines
    friend ostream &operator<<(ostream &os, const Book &book);

    //check if book is available, returns true if it is
    bool isBookAvailable(){ return isAvailable;}

    //get the book's name, for printing reasons
    string getName(){ return title;}

    // flips the book's availability status
    void changeAvailability(bool status){
        isAvailable = status;
    }
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
        // at last position, check if it is a letter or digit
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
bool Book::operator==(const Book &comapredBook)
{
    if (isbnNumber == comapredBook.isbnNumber)
        return true;
    return false;
}
bool Book::operator!=(const Book &comapredBook)
{
    if (isbnNumber != comapredBook.isbnNumber)
        return true;
    return false;
}

// global output function for pushing Book object to the output buffer
ostream &operator<<(ostream &os, const Book &book)
{
    os << "\n\nBook Name: " << book.title;
    os << " , Written by: " << book.authorName;
    os << "\nGenre ID: " << static_cast<int>(book.genre);
    os << "\nAvailibilty status: " << ((book.isAvailable) ? "Yes" : "No");
    os << "\nISBN: " << book.isbnNumber << " , copyright: " << book.copyright << '\n';
    return os;
}

// customer class, has the name, id and fee they owe
class Patron
{
private:
    // name, uniqueID and fee of the customer
    string name;
    int libraryCardNumber;
    double feeOwed;

public:
    // constructor function for the customer
    Patron(string inputName, int inputID, double inputFee) : name{inputName},
                                                             libraryCardNumber{inputID},
                                                             feeOwed{inputFee}
    {
    }
    // functions to READ the information
    string getName() const { return name; }
    int getID() { return libraryCardNumber; }
    double getFee() const { return feeOwed; }

    // function to edit the fee the customer owes
    void editFee(double inputFee) { feeOwed += inputFee; }

    // to check if the customer owes any fee or not
    bool hasPendingFee() const
    {
        return feeOwed > 0;
    }
};

// Records a transcation which has happened, stores its date
struct Transaction
{
    Book name;
    Patron customerName;
    Date transactionDate;

    Transaction(const Book &b, const Patron &p, const Date &d)
        : name(b), customerName(p), transactionDate(d) {}
};

// primary library class to keep a record of the patrons and the books
class Library
{
private:
    // stores every book currently available in the library
    vector<Book> bookshelf;
    // stores a list of valid customers, i.e, have a valid id
    vector<Patron> customers;
    //stores all the transaction records
    vector<Transaction> transactionRecords;

public:
    // adds a book to the library
    void addBook(Book inputBook) { bookshelf.push_back(inputBook); }
    // adds a patron to the library list
    void addPatron(Patron inputPatron) { customers.push_back(inputPatron); }
    // makes an attempt to buy a boook
    void checkoutBook(Patron &buyingCustomer, Book &item, Date &transDate);
    // prints the list of every patron that owes money
    vector<string> printDebters();
};

// checks if the book and patron are valid, if so, check if patron is in debt, if not, complete transaction
void Library::checkoutBook(Patron &buyingCustomer, Book &item, Date &transDate)
{
    cout << "\nAttempting to check out a book...\n";
    // check if patron exists in record
    {
        bool patronExists{false};
        for(auto& i : customers){
            if(i.getName() == buyingCustomer.getName()){
                patronExists = true;
                break;
            }
        }
        if (!patronExists)exit(1);
    }
    // check if book exists in record
    {
        bool bookExists{false};
        for(auto& i : bookshelf){
            if(i == item){
                bookExists = true;
                break;
            }
        }
        if (!bookExists)exit(1);
    }
    // check if patron owes money
    if(buyingCustomer.hasPendingFee()) exit(1);

    //check if book is available or not
    if(!item.isBookAvailable()) exit(1);

    //if the function has survived so far, complete the transaction
    transactionRecords.push_back(Transaction(item, buyingCustomer, transDate));
    //after transaction is pushed, make book unavailable
    item.changeAvailability(false);
    cout << "Book " << item.getName() << " checked out successfully!\n";
}

vector<string> Library::printDebters(){
    vector<string> debters;
    for(auto& i : customers){
        if(i.hasPendingFee()){
            debters.push_back(i.getName());
        }
    }
    return debters;
}

int main()
{
    Date d1(Year{2054}, Month::jan, 26);
    cout << d1.dayOfTheYear();
    return 0;
}
