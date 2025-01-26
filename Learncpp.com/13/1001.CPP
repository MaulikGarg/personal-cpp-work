#include<iostream>
using namespace std;

struct adStats {
    
    int adsWatched {};
    double percentOfUsersClicked {};
    double avgEarningsPerClick {};

};

void printAdStats(adStats& stats){
    cout << "Ads watched in total: " << stats.adsWatched;
    cout << "\nPercentage of users clicking on ads: " << stats.percentOfUsersClicked;
    cout << "\nAverage earning per user click: $" << stats.avgEarningsPerClick;
}

int main()
{
    adStats learncpp {69,69.69,6.9};
    printAdStats(learncpp);
    return 0;
}
