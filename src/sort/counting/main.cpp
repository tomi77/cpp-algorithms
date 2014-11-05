/**
 * Sorting integers - bubble method.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "util.h"
#include "csort.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int size;
	vector<int> v;

	if (argc == 2)
	{
		size = atoi(argv[1]);
	}
	else
	{
		cout << "How many: ";
		cin >> size;
	}

	fillVector(v, size);

	if (size < 100)
	{
		cout << endl << "Before: ";
		printVector(v);

		sort::counting(v);

		cout << endl << "After: ";
		printVector(v);

	}
	else
	{
		sort::counting(v);
	}

	return 0;
}