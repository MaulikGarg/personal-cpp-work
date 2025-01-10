#include<iostream>
using namespace std;

// #define OTHER_METHOD 1
#ifdef OTHER_METHOD
int printbinarydigit(int x, int numberMax){
    cout << x/numberMax;
    return x%numberMax;
}
#endif

int main()
{
    int x{};
    cout << "Enter a number: ";
    cin >> x;
    cout << "The number you entered is: ";

    for (int maxNumber = 128; maxNumber > 0; maxNumber/=2)
    {
        cout << x/maxNumber;
        x%=maxNumber;
        if (maxNumber == 16) cout << " ";
    }
    
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
