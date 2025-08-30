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
    Year y;
    Month m;
    int d;
    void is_valid(Month mm, int dd);

public:
    Date() : y{2000}, m{Month::jan}, d{1} {} // constructors
    Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {is_valid(mm,dd);}

    int getDay() const { return d; }
    Month getMonth() const { return m; }
    Year getYear() const { return y; }

    void incrementDay(int n) { d += n; }
};

void Date::is_valid(Month mm, int dd){
    if(dd > 31 || dd < 1) exit(1);
    if(static_cast<int>(mm) > 12 || static_cast<int>(mm) < 1) exit(1);
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    return os << date.getYear().value << "-"
              << static_cast<int>(date.getMonth()) << "-"
              << date.getDay();
}

int main()
{
    Date today{Year{2020}, Month::feb, 2};
    cout << today << '\n';
    today.incrementDay(1);
    Date tomorrow {today};
    cout << tomorrow;
    
    return 0;
}
