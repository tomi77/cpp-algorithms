#include <iostream>
#include <algorithm>
#include "fib.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
	}
	else
	{
		cout << "Which element?: ";
		cin >> n;
	}

	cout << fib(n);

	return 0;
}