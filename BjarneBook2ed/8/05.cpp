#include<iostream>
#include<vector>
using namespace std;
using vectOfInts = vector<int>;

auto revVectorCopy(vectOfInts vev) -> vectOfInts
{
    int currentLastVariable = static_cast<int>(vev.size());
    vectOfInts newVev;
    for(auto _ : vev){ //_ indicates unused variable.
        newVev.push_back(vev[currentLastVariable-1]);
        currentLastVariable--;
    }
    return newVev;
}

void revVectorRef(vectOfInts& vev){
    int vecElementCount = static_cast<int>(vev.size());

    int firstIterator{0};
    int lastIterator {vecElementCount-1};
    
    for (int i = 0; i < vecElementCount/2; i++)
    {
        swap(vev[firstIterator],vev[lastIterator]);
        firstIterator++;
        lastIterator--;
    }
}

int main()
{
    vectOfInts start {1,2,3,4,5};
    for(int i: revVectorCopy(start)){
        cout << i << ' ';
    }
    cout << '\n';
    revVectorRef(start);
    for(int i: start){
        cout << i << ' ';
    }

    return 0;
}
