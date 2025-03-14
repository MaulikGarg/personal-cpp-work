#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printElement(const std::vector<T>& vv, int index){
    if(vv.size() - index < 1 || index < 0) {
        cerr << "bad index.\n";
        return;
    }
    cout << vv[index] << '\n';
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
