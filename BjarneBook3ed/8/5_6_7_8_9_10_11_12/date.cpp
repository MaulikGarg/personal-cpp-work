#include <iostream>
#include <cmath>
using std::exit;

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
