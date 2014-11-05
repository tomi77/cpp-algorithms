/**
 * Sorting integers - bubble method.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../util.h"
#include "bsort.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int size, i, n;
	vector<int> v;

	cout << "How many: ";
	cin >> size;

	fillVector(v, size);	

	cout << endl << "Before: ";
	printVector(v);

	sort::bubble(v);

	cout << endl << "After: ";
	printVector(v);

	return 0;
}