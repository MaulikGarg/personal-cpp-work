#include<iostream>
using namespace std;

struct adStats {
    
    int adsWatched {};
    double percentOfUsersClicked {};
    double avgEarningsPerClick {};

};

void getAdStats(adStats& stats){
    cout << "How many ads were seen today?\n>> ";
    cin >> stats.adsWatched;
    cout << "What percentage of users clicked them? \n>> ";
    cin >> stats.percentOfUsersClicked;
    cout << "What is the average earning per click? \n>> ";
    cin >> stats.avgEarningsPerClick;
}

void printAdStats(const adStats& stats){
    cout << "\nAds watched in total: " << stats.adsWatched;
    cout << "\nPercentage of users clicking on ads: " << stats.percentOfUsersClicked;
    cout << "\nAverage earning per user click: $" << stats.avgEarningsPerClick;
    double total {(stats.adsWatched*stats.percentOfUsersClicked*stats.avgEarningsPerClick)/100};
    cout << "\nTotal revenue: $" << total;
}

int main()
{
    adStats learncpp {};
    getAdStats(learncpp);
    printAdStats(learncpp);
    return 0;
}
