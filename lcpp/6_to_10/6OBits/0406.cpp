#include<iostream>
using namespace std;

//#define WHILE_METHOD 1
//#define OTHER_METHOD 1

#ifdef OTHER_METHOD
int printbinarydigit(int x, int numberMax){
    cout << x/numberMax;
    return x%numberMax;
}
#endif

int main()
{
    
    int maxNumber = 128; 
    cout << "Enter a number less than " << 2*maxNumber << endl; 
    int x{};
    cin >> x;
    cout << "The number you entered is: ";

    #ifdef WHILE_METHOD
    int counter{1};
    while (maxNumber > 0)
    {
        cout << x / maxNumber;
        x %= maxNumber;
        if (counter++ % 4 == 0) cout << " ";  
        maxNumber /= 2;
    }
    #endif

    #ifdef OTHER_METHOD
    x = printbinarydigit(x, 128);
    x = printbinarydigit(x, 64);
    x = printbinarydigit(x, 32);
    x = printbinarydigit(x, 16);

    cout << " ";

    x = printbinarydigit(x, 8);
    x = printbinarydigit(x, 4);
    x = printbinarydigit(x, 2);

    cout << x << endl; 
    #endif

    return 0;
}
