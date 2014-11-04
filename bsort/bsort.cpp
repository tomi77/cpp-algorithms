/**
 * Sorting integers - bubble method.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubblesort(vector<int> &v)
{
	int i, change;
	
	do
	{
		change = 0;
		i = v.size() - 1;
		
		do
		{
			if (v[i] < v[--i])
			{
				swap(v[i], v[i + 1]);
				change = 1;
			}
		}
		while (i != 0);
	}
	while (change != 0);
}

int main(int argc, char const *argv[])
{
	int count, i, n;
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

	bubblesort(v);

	cout << endl << endl << "After: ";
	for (i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}