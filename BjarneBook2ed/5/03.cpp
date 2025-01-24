#include <iostream>
#include <iomanip>
using namespace std;

void err(string errorstring){
    cerr << errorstring;
    exit(1);
}
double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}
int main()
{
    double c = 0;         // declare input variable
    cin >> c;  
    if(c < (-273.15)) err("Temperature below absolute zero.");     // retrieve temperature to input variable
    cout << ctok(c) << '\n';    // print out temperature
}
