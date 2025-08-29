/*
Below are 25 code fragments. Each is meant to be inserted into this “scaffolding”:


    #include "std_lib_facilities.h"
    int main()
    try {
    <<your code here>>
    keep_window_open();
    return 0;
    }
    catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
    }
    catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
    }

Each has zero or more errors. Your task is to find and remove all errors in each program. When you
have removed those bugs, the resulting program will compile, run, and write “Success!” Even if you
think you have spotted an error, you still need to enter the (original, unimproved) program fragment
and test it; you may have guessed wrong about what the error is, or there may be more errors in a
fragment than you spotted. Also, one purpose of this drill is to give you a feel for how your compiler
reacts to different kinds of errors. Do not enter the scaffolding 25 times — that’s a job for cut and
paste or some similar “mechanical” technique. Do not fix problems by simply deleting a statement;
repair them by changing, adding, or deleting a few characters.


    1. Cout << "Success!\n";
    2. cout << "Success!\n;
    3. cout << "Success" << !\n"
    4. cout << success << '\n';
    5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
    7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
    10. string s = "ape"; if (s=="fool") cout << "Success!\n";
    11. string s = "ape"; if (s=="fool") cout < "Success!\n";
    12. string s = "ape"; if (s+"fool") cout < "Success!\n";
    13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
    14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
    16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
    17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
    18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
    19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
    21. int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
    22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
    23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
    24. int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";
    25. cin << "Success!\n";

*/


#include <iostream>
#include <vector>
using namespace std;

// #define ONE
// #define TWO
// #define THREE
// #define FOUR
// #define FIVE
// #define SIX
// #define SEVEN
// #define EIGHT
// #define NINE
// #define TEN
// #define ELEVEN
// #define TWELVE
// #define THIRTEEN
// #define FOURTEEN
// #define FIFTEEN
// #define SIXTEEN
// #define SEVENTEEN
// #define EIGHTEEN
// #define NINETEEN
// #define TWENTY
// #define TWENTYONE
// #define TWENTYTWO
// #define TWENTYTHREE
// #define TWENTYFOUR
// #define TWENTYFIVE

int main()
try
{
#ifdef ONE
    cout << "Success!\n";
#endif

#ifdef TWO
    cout << "Success!\n";
#endif

#ifdef THREE
    cout << "Success" << "!\n";
#endif

#ifdef FOUR
    cout << "success" << '\n';
#endif

#ifdef FIVE
    int res = 7;
    vector<int> v(10);
    v[5] = res;
    cout << "Success!\n";
#endif

#ifdef SIX
    vector<int> v(10);
    v[5] = 7;
    if (v[5] == 7) cout << "Success!\n";
#endif

#ifdef SEVEN
    bool cond {1};
    if (cond) cout << "Success!\n";
    else cout << "Fail!\n";
#endif

#ifdef EIGHT
    bool c = false;
    if (!c)
        cout << "Success!\n";
    else
        cout << "Fail!\n";
#endif

#ifdef NINE
    string s = "ape";
    bool c = "fool" > s;
    if (c)
        cout << "Success!\n";
#endif

#ifdef TEN
    string s = "ape";
    if (s != "fool")
        cout << "Success!\n";
#endif

#ifdef ELEVEN
    string s = "ape";
    if (s != "fool")
        cout << "Success!\n";
#endif

#ifdef TWELVE
    string s = "ape";
    if (s + "fool" == "apefool")
        cout << "Success!\n";
#endif

#ifdef THIRTEEN
    vector<char> v(5);
    for (int i = 0; i < v.size(); ++i)
        ;
    cout << "Success!\n";
#endif

#ifdef FOURTEEN
    vector<char> v(5);
    for (int i = 0; i < v.size(); ++i)
        ;
    cout << "Success!\n";
#endif

#ifdef FIFTEEN
    string s = "Success!\n";
    for (int i = 0; i < 9; ++i)
        cout << s[i];
#endif

#ifdef SIXTEEN
    if (true)
        cout << "Success!\n";
    else
        cout << "Fail!\n";
#endif

#ifdef SEVENTEEN
    int x = 2000;
    int c = x;
    if (c == 2000)
        cout << "Success!\n";
#endif

#ifdef EIGHTEEN
    string s = "Success!\n";
    for (int i = 0; i < s.size(); ++i)
        cout << s[i];
#endif

#ifdef NINETEEN
    vector<int> v(5);
    for (int i = 0; i < v.size(); ++i)
        ;
    cout << "Success!\n";
#endif

#ifdef TWENTY
    int i = 0;
    int j = 9;
    while (i < 10)
        ++i;
    if (j < i)
        cout << "Success!\n";
#endif

#ifdef TWENTYONE
    int x = 2;
    double d = 9.0 / (x);
    if (d == 2 * x + 0.5)
        cout << "Success!\n";
#endif

#ifdef TWENTYTWO
    string s = "Success!\n";
    for (int i = 0; i < s.size(); ++i)
        cout << s[i];
#endif

#ifdef TWENTYTHREE
    int i = 0;
    int j = 9;
    while (i < 10)
        ++i;
    if (j < i)
        cout << "Success!\n";
#endif

#ifdef TWENTYFOUR
    int x = 4;
    double d = 9.0 / (x-2);
    if (d = 2 * x + 0.5)
        cout << "Success!\n";
#endif

#ifdef TWENTYFIVE
    cout << "Success!\n";
#endif

    return 0;
}
catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    return 2;
}
