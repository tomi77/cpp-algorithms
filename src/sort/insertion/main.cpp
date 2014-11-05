/**
 * Sorting integers - insertion sort method.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../util.h"
#include "isort.h"

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

	sort::insertion(v);

	cout << endl << "After: ";
	printVector(v);

	return 0;
}