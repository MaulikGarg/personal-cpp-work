#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr){
    for(size_t i = 0; i <arr.size(); i++){
        std::cout << arr[i] << ' ';
    }
    if (arr.size() > 0)
        std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr); // use function template to print array

    return 0;
}
