#include<iostream>
#include<string>
#include<vector>
using namespace std;
using vecint = vector<int>;

int maxv(const vecint& vev){
    int largest{vev[0]};
    for(int i: vev){
        if(i > largest) {
            largest = i;
        }
    }
    return largest;
}

int main()
{
    vecint myVec{2,3,4};
    cout << maxv(myVec);

    return 0;
}
