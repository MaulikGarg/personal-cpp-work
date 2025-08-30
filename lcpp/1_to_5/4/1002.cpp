#include<iostream>
using namespace std;

int main()
{

	cout << "enter 1-9: ";
	int n{};
	cin >> n;
	if (n == 1 || n == 2 || n ==3 || n == 5 || n == 7)
	{
		cout << "prime";
	}
	else if (n == 4 || n == 6 || n == 8 || n == 9)
	{
		cout << "not prime";
	}
	else
	{
		cout << "invalid";
	}
	return 0;
}
