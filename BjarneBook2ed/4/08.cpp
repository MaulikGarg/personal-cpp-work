#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>

//using namespace std;

int main()
{
    double rice{};
    double riceOnSquare{1};
    bool hasOneThousand {false};
    bool hasOneMillion {false};
    bool hasOneBillion {false};

    for(int i {1}; i <= 64; i++){
        riceOnSquare *= 2;
        rice += riceOnSquare;
        if (!hasOneThousand && rice>=1000)
        {
            std::cout << "One thousand rice after " << i << " squares.\n";
            hasOneThousand = true;
        }
        if (!hasOneMillion && rice>=1'000'000)
        {
            std::cout << "One million rice after " << i << " squares.\n";
            hasOneMillion = true;
        }
        if (!hasOneBillion && rice>=1'000'000'000)
        {
            std::cout << "One billion rice after " << i << " squares.\n";
            hasOneBillion = true;
        }
        
    }

    return 0;
}
