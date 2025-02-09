#include<iostream>
#include<string>
#include<string_view>
#include<utility>
#include<vector>
using namespace std;

template <typename T>
pair<size_t, size_t> minmax(const vector<T>& list){
    pair<size_t, size_t> minmax {0,0};
    T min = list[0];
    T max = list[0];
    for(size_t i = 0; i < list.size(); i++){
        if(min > list[i]){
            minmax.first = i;
            min = list[i];
        }
        if(max < list[i]){
            minmax.second = i;
            max = list[i];
        }
    }
    return minmax;
}

template <typename T>
void printminmax(const vector<T>& list, const pair<size_t, size_t>& minmax){
    cout << "With array ( ";
    for(size_t i = 0; i < list.size(); i++){
        cout << list[i];
        cout << (i == (list.size() - 1) ? " )\n" : ", ");
    }
    cout << "The min element has index " << minmax.first << " and value " << list[minmax.first] << '\n';
    cout << "The max element has index " << minmax.second << " and value " << list[minmax.second] << '\n';
}

int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    printminmax(v1, minmax(v1));
    printminmax(v2, minmax(v2));

    return 0;
}
