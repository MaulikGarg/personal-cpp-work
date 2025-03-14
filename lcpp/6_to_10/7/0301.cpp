#include <iostream>

using namespace std;

int main()
{
  //getting initial integer
  cout << "Enter an integer: ";
  int smaller{}; //smaller's life starts
  cin >> smaller;

  cout << "Enter a larger integer: ";
  int larger{}; //larger's life starts
  cin >> larger;

  //swapping if user enters a smaller number
  if (larger < smaller)
  {
    cout << "Swapping the values\n";
    [[maybe_unused]] int temp{smaller}; //temp's life starts
    smaller = larger;
    larger = smaller;
  } //temp's life ends

  //final print
  cout << "The smaller value is: " << smaller << '\n';
  cout << "The larger value is: " << larger << '\n';

  return 0;
} //smaller and larger's lives ends
