#include <iostream>
using std::exit;

//month used for the date.
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

//structure year used inside a date
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
    Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {is_valid(mm,dd);}

    //print the day month or year
    int getDay() const { return d; }
    Month getMonth() const { return m; }
    Year getYear() const { return y; }

    //increment the day by 1
    void incrementDay(int n) { d += n; }

    //checks if the current year is a leap year, return true if it is
    bool isLeapYear();
};

//checks if the date is valid by checking month and date availability
void Date::is_valid(Month mm, int dd){
    if(dd > 31 || dd < 1) exit(1);
    if(static_cast<int>(mm) > 12 || static_cast<int>(mm) < 1) exit(1);
}

//return true if the object is a leap year.
bool Date::isLeapYear(){
    if(y.value%400 == 0) return true;
    if(y.value%4 == 0 && y.value%100 != 0) return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    return os << date.getYear().value << "-"
              << static_cast<int>(date.getMonth()) << "-"
              << date.getDay();
}
