#include <iostream>
using namespace std;

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

struct Year
{
    int value;
    explicit Year(int v) : value(v) {}
};

class Date
{
private:
    int d;
    Month m;
    Year y;

public:
    Date() : y{2000}, m{Month::jan}, d{1} {} // constructors
    Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}

    int getDay() const { return d; }
    Month getMonth() const { return m; }
    Year getYear() const { return y; }

    void incrementDay(int n) { d += n; }
};

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    return os << date.getYear().value << "-"
              << static_cast<int>(date.getMonth()) << "-"
              << date.getDay();
}

int main()
{
    Date today{Year{2020}, Month::feb, 02};
    cout << today;
    
    return 0;
}
