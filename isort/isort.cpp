/**
 * Sorting integers - insertion sort method.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionsort(vector<int> &v)
{
	int i, j, k;

	for (i = 0; i < v.size(); ++i)
	{
		j = i;
		k = v[i];

		while (v[j - 1] > k && j > 0)
		{
			v[j] = v[j - 1];
			--j;
		}
		v[j] = k;
	}
}

int main(int argc, char const *argv[])
{
	int count, i, j;
	vector<int> v;

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

	insertionsort(v);

	cout << endl << endl << "After: ";
	for (i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}