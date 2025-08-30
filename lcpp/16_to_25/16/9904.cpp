#include <iostream>
#include <string>
#include <limits>
#include <string_view>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
pair<size_t, size_t> minmax(const vector<T> &list)
{
    pair<size_t,size_t> minmax{0,0};
    T min = list[0];
    T max = list[0];
    for (size_t i = 0; i < list.size(); i++)
    {
        if (min > list[i])
        {
            minmax.first = i;
            min = list[i];
        }
        if (max < list[i])
        {
            minmax.second = i;
            max = list[i];
        }
    }
    return minmax;
}

template <typename T>
void printminmax(const vector<T> &list, const pair<size_t, size_t> minmax)
{
    cout << "The min element has index " << minmax.first << " and value " << list[minmax.first] << '\n';
    cout << "The max element has index " << minmax.second << " and value " << list[minmax.second] << '\n';
}

template <typename T>
void printlist(const vector<T> &list)
{
    cout << "With array ( ";
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list[i];
        cout << (i == (list.size() - 1) ? " )\n" : ", ");
    }
}

int main()
{
    cout << "Enter numbers to add (use -1 to stop): ";
    vector<int> list;
    while (true)
    {
        int temp;
        cin >> temp;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            if (temp == -1)
                break;

            list.push_back(temp);
        }
    }
    
    if (list.size() == 0)
    {
        cout << "The list has no elements.";
    } else {
        printlist(list);
        printminmax(list, minmax(list));
    }


    return 0;
}
