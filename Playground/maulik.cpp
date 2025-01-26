/*port of my older project into single file for testing purposes*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// month used for the date.
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

// structure year used inside a date
struct Year
{
    int value;
    explicit Year(int v) : value(v) {}
};

class Date
{
private:
    Year y;
    Month m;
    int d;
    void is_valid(Month mm, int dd);

public:
    Date() : y{2000}, m{Month::jan}, d{1} {} // constructors
    Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} { is_valid(mm, dd); }

    // print the day month or year
    int getDay() const { return d; }
    Month getMonth() const { return m; }
    Year getYear() const { return y; }

    // increment the day by 1
    void incrementDay(int n) { d += n; }

    // checks if the current year is a leap year, return true if it is
    bool isLeapYear();

    // returns the current week of the year, i.e, starting from Jan 1
    int weekOfTheYear();

    // returns the number of days left until the next workday, ranges from 0 to 2.
    int nextWorkday();

    // returns the day of the year.. sunday is 0.. saturday is 6. uses default val JAN 1
    int dayOfTheYear();

    // returns the number of days it has passed since Jan 1 XXXX
    int numberOfDays();
};

// checks if the date is valid by checking month and date availability
void Date::is_valid(Month mm, int dd)
{
    if (dd > 31 || dd < 1)
        exit(1);
    if (static_cast<int>(mm) > 12 || static_cast<int>(mm) < 1)
        exit(1);
}

// return true if the object is a leap year.
bool Date::isLeapYear()
{
    if (y.value % 400 == 0)
        return true;
    if (y.value % 4 == 0 && y.value % 100 != 0)
        return true;
    return false;
}

// assumes that default date is 1st of jan
int Date::dayOfTheYear()
{
    // uses the zeller's congurence formula
    //  m is month, 3=march 11=nov..14=feb
    // adjust jan and feb
    int month = static_cast<int>(m);
    int year = y.value;
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }
    int yearInCentury{year % 100};
    int zeroBasedCentury{year / 100}; // integer division intended

    // formula itself
    double innerBracket = floor((13 * (month + 1)) / 5.0);
    double outerBracket = d + innerBracket + yearInCentury + floor(yearInCentury / 4.0) + floor(zeroBasedCentury / 4.0) - 2 * zeroBasedCentury;

    // 0=sunday...4=thursday..6=saturday
    return (static_cast<int>(outerBracket) % 7) - 1;
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    return os << date.getYear().value << "-"
              << static_cast<int>(date.getMonth()) << "-"
              << date.getDay();
}

int Date::nextWorkday()
{
    int day{dayOfTheYear()};
    // if its sunday..monday...thursday, then workday is tomrw
    if (day < 5)
        return 0;
    // if its a friday, workday is in 2 days
    if (day == 5)
        return 2;
    // if its a saturday, workday is in 1 day.
    if (day == 6)
        return 1;

    return -1; // indicates error
}
int Date::numberOfDays()
{
    int month = static_cast<int>(m) - 1;
    int totalDays{d};
    bool flip{false}; //while months are less than august, increment odd months by 31, 
                        //after that, do even ones
    for (int i = 1; i <= month; i++)
    {
        if(flip){
            //if its flipped, increment even months by 31
            if(i%2==0) totalDays+=31;
            else totalDays+=30;
        } else {
            //if its unflipped, increment odd months by 31
            if((i%2!=0)) totalDays +=31;
            //if even and not feb, add by 30
            else if(i!=2) totalDays +=30;
            else{
                //check if its a leap year, increment by 29 if it is
                if(isLeapYear()) totalDays +=29;
                else totalDays +=28;
            }
        }
        if(i==6) flip = true;
    }
    return totalDays;
}

int Date::weekOfTheYear()
{
    // first we need to get the day that was on jan 1
    Date temporary{y, Month::jan, 1};
    int dayOnJanFirst{temporary.dayOfTheYear()}; // returns 0 if sunday and 6 is saturday..
    int daysPassed = numberOfDays(); //get the number of the day it currently is in a year
    int adjustedDays {daysPassed+dayOnJanFirst}; //if jan 1 was not a sunday, add the day number to allign the day with a sunday
    int weekNumber = (adjustedDays + 6) / 7; //6 is added to make the days fully divisible by 7.
    return weekNumber;
    
}

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
