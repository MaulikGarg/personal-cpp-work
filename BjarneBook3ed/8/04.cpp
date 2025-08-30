/*this program defines a namepairs class which stores pairs of names and ages*/
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
using namespace std;

//individual namepair, only has one name and respective age
class Name_Pair
{
private:
    //respective name and age for a pair object
    string name;
    double age;

public:
    //constructor with arguements for initialization
    Name_Pair(string inputName, double inputAge) : name(inputName), age(inputAge) {}
    //returns the currently set name
    string getName() const { return name; }
    //returns the currently set age
    double getAge() const { return age; }
    //changes the name to a new name passed as arguement
    void setName(string newName) { name = newName; }
    //changes the age to a new age passed
    void setAge(double NewAge) { age = NewAge; }
};

//stores pairs of names using class name pair
class Name_Pairs
{
private:
    //vec to store all namepairs in this namepair object, it is a collection of pairs
    vector<Name_Pair> namepair;

public:
    //gets all the names into their namepair object
    void inputNames();
    //gets the ages, equal to the number of objects entered
    void inputAges();
    //sorts the given namepair
    void mysort();
    //used for comparing the name pairs, not individual ones
    bool operator==(const Name_Pairs &comparedPairs) const;
    bool operator!=(const Name_Pairs &comparedPairs) const;
    //friend function for the output operation
    friend ostream &operator<<(ostream &os, const Name_Pairs &pair);
};

void Name_Pairs::inputNames()
{
    //gets the names into namepairs until zero is entered
    cout << "Enter Names(0 to eliminate): ";
    string temp{};
    while (true)
    {
        cin >> temp;
        if (temp == "0")
            return;
        namepair.push_back(Name_Pair(temp, 0));
    }
}

void Name_Pairs::inputAges()
{
    //gets the number of ages corresponding to the number of names entered previously
    if (namepair.size() < 1)
        exit(1);
    for (int i = 0; i < static_cast<int>(namepair.size()); i++)
    {
        cout << "Enter " << namepair[i].getName() << "'s age: ";
        double temp{};
        cin >> temp;
        namepair[i].setAge(temp);
    }
}

//returns true if n1 comes before n2, need for mySort()
bool isNamePairgreater (Name_Pair& n1, Name_Pair& n2){
    return (n1.getName() < n2.getName());
}

//sorts the set of namepairs 
void Name_Pairs::mysort()
{
    sort(namepair.begin(), namepair.end(), isNamePairgreater);
}

ostream &operator<<(ostream &os, const Name_Pairs &pair)
{
    //prints a newline and sends the current namepair to the output buffer
    os << '\n';
    for (int i = 0; i < static_cast<int>(pair.namepair.size()); i++)
    {
        os << pair.namepair[i].getName() << " has age: " << pair.namepair[i].getAge() << '\n';
    }
    return os;
}

//first checks if size is equal, then for each pair, checks name then corresponding age
bool Name_Pairs::operator==(const Name_Pairs &comparedPairs) const {
    if (namepair.size() != comparedPairs.namepair.size()) return false;
    for (int i = 0; i < static_cast<int>(namepair.size()); i++)
    {
        if(namepair[i].getName() != comparedPairs.namepair[i].getName()) return false;
        if(namepair[i].getAge() != comparedPairs.namepair[i].getAge()) return false;
    }
    return true;
}

bool Name_Pairs::operator!=(const Name_Pairs &comparedPairs) const {
    if (namepair.size() != comparedPairs.namepair.size()) return true;
    for (int i = 0; i < static_cast<int>(namepair.size()); i++)
    {
        if(namepair[i].getName() != comparedPairs.namepair[i].getName()) return true;
        if(namepair[i].getAge() != comparedPairs.namepair[i].getAge()) return true;
    }
    return false;
}

int main()
{
    Name_Pairs students;
    students.inputNames();
    students.inputAges();
    students.mysort();
    cout << students;

    return 0;
}
