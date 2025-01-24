#include<iostream>
#include<string>
#include<vector>
using namespace std;
using vecint = vector<int>;

void maxv(vecint& vev, int& smallest, int& largest, double& mean, int& median){
    int sum{};
    for(int i: vev){
        if(i > largest) {
            largest = i;
        }
        if(i < smallest) {
            smallest = i;
        }
        sum+=i;
    }
    int totalsize = vev.size();
    mean = static_cast<double>(sum)/totalsize;
    sort(vev.begin(), vev.end());
    if(totalsize%2 == 0){
        median = (vev[totalsize/2 - 1] + vev[totalsize/2]) / 2;
    } else {
        median = vev[totalsize/2];
    }

}

int main()
{
    vecint myVec{2,3,4,4,53,2,4,2};
    int largest{myVec[0]};
    int smallest{myVec[0]};
    double mean;
    int median;
    maxv(myVec, smallest, largest, mean, median);

    cout << largest << '\n';
    cout << smallest << '\n';
    cout << mean << '\n';
    cout << median << '\n';

    return 0;
}
