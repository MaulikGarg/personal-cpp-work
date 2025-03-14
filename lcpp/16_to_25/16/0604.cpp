#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template<typename T>
int findInArray(T num, vector<T>arr){
    for(size_t i = 0; i < arr.size(); i++){
        if(arr[i] == num) return static_cast<int>(i);
    }
    return -1;
}

template <typename T>
void printArray(const std::vector<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ",  ";
    }
    if (arr.size() > 0)
        std::cout << '\n';
}

template<typename T> 
T getValidNumber(T low, T high)
{
    T num;
    while (true)
    {
        std::cout << "Enter a number between " << low <<  " and " << high << " :  ";
        cin >> num;
        if (!cin)
            cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(num >= low && num <= high) break;
    }
    return num;
}

int main()
{
    std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};
    auto num{getValidNumber(1.0,9.9)};
    printArray(arr);
    int index {findInArray(num, arr)};
    cout << "The number " << num;
    if(index == -1){
        cout << " was not found.\n";
    } else {
        cout << " has index " << index << ".\n";
    }
    return 0;
}
