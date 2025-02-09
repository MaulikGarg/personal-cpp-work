#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

void iGiveErrors(string s)
{
    cerr << "error: " << s << '\n';
    exit(1);
}



int main()
{
    vector<char> computerMoves;
    cout << "How many moves should the computer have? : ";
    int input{};
    cin >> input;
    if (input < 1)
        iGiveErrors("It must have 1 move!");

    cout << "Enter computer moves(r/s/p): ";
    for (int i = 0; i < input; i++)
    {
        char move{};
        cin >> move;
        if ((move != 'r') && (move != 's') && (move != 'p'))
        {
            iGiveErrors("Invalid input");
        }
        computerMoves.push_back(move);
    }

    for (int counter = 0; counter < computerMoves.size(); counter++)
    {
        cout << "Enter your move!\n move: ";
        char move{};
        cin >> move;
        if ((move != 'r') && (move != 's') && (move != 'p'))
        {
            iGiveErrors("Invalid input");
        }

        switch (move)
        {
        case 'r':
            if (computerMoves[counter] == 'p')
                cout << "Computer won!\n";
            else if (computerMoves[counter] == 's')
                cout << "You won!\n";
            else
                cout << "Tie!";
            break;
        case 's':
            if (computerMoves[counter] == 'r')
                cout << "Computer won!\n";
            else if (computerMoves[counter] == 'p')
                cout << "You won!\n";
            else
                cout << "Tie!";
            break;
        case 'p':
            if (computerMoves[counter] == 's')
                cout << "Computer won!\n";
            else if (computerMoves[counter] == 'r')
                cout << "You won!\n";
            else
                cout << "Tie!";
            break;

        default:
            break;
        }
    }
    return 0;
}
