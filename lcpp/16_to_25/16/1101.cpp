#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void print(const vector<int> &stack)
{
    cout << "\t(Stack: ";
    if (stack.size() == 0)
    {
        cout << "empty)\n";
        return;
    }
    else
    {
        for (auto element : stack)
            std::cout << element << ' ';
        cout << ")\n";
    }
}

void printpush(vector<int> &stack, int pushed)
{
    stack.push_back(pushed);
    cout << "Push " << pushed << " ";
    print(stack);
}

void printpop(vector<int> &stack)
{
    stack.pop_back();
    cout << "Pop ";
    print(stack);
}

int main()
{
    std::vector<int> v {};

    print(v);

    printpush(v, 1);
    printpush(v, 2);
    printpush(v, 3);
    printpop(v);
    printpush(v, 4);
    printpop(v);
    printpop(v);
    printpop(v);

    return 0;
}
