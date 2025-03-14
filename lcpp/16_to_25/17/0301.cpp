#include <array>
#include <iostream>

using namespace std;

template <typename T, size_t N>
void printArray(const array<T,N>& arr){
    cout << "The array (";
    for(const auto& i: arr){
        cout << i;
        if(!(i==arr[N-1])) cout << ", ";
    }
    cout << ") has length " << N << '\n';

}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
