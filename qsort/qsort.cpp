/**
 * Sorting integers - quick sort method.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quicksort(vector<int> &v, const int x, const int y)
{
	int i = x, j = y, k = v[div(x + y, 2).quot];

	do
	{
		while (v[i] < k) ++i;
		while (k < v[j]) --j;
		if (i <= j)
		{
			swap(v[i++], v[j--]);
		}
	}
	while (i <= j);
	if (x < j) quicksort(v, x, j);
	if (i < y) quicksort(v, i, y);
}

int main(int argc, char const *argv[])
{
	int count, i, n;
	vector<int> v;

	srand(time(0));

	cout << "How many: ";
	cin >> count;
	
	for (i = 0; i < count; ++i)
	{
		v.push_back(rand() % count);
	}

	cout << endl << "Before: ";
	for (i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	quicksort(v, 0, v.size() - 1);

	cout << endl << endl << "After: ";
	for (i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}