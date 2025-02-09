#include<iostream>
#include<string>
#include<vector>
using namespace std;
using vectOfStrings = vector<string>;

auto revVectorCopy(vectOfStrings vev) -> vectOfStrings
{
    int currentLastVariable = static_cast<int>(vev.size());
    vectOfStrings newVev;
    for(auto _ : vev){ //_ indicates u  nused variable.
        newVev.push_back(vev[currentLastVariable-1]);
        currentLastVariable--;
    }
    return newVev;
}

void revVectorRef(vectOfStrings& vev){
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
    vectOfStrings start;
    for(string i: revVectorCopy(start)){
        cout << i << ' ';
    }
    cout << '\n';
    revVectorRef(start);
    for(string i: start){
        cout << i << ' ';
    }

    return 0;
}
