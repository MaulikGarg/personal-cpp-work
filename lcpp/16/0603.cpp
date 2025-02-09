#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template<typename T>
T findInArray(T num, vector<T>arr){
    for(size_t i = 0; i < arr.size(); i++){
        if(arr[i] == num) return static_cast<T>(i);
    }
    return -1;
}

template <typename T>
void printArray(const std::vector<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
    if (arr.size() > 0)
        std::cout << '\n';
}

int getValidNumber()
{
    int num;
    while (true)
    {
        std::cout << "Enter a number between 1 and 9:  ";
        cin >> num;
        if (!cin)
            cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(num >= 1 && num <= 9) break;
    }
    return num;
}

int main()
{
    std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
    int num{getValidNumber()};
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
