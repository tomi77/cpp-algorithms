/**
 * Sorting integers - bubble method.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void b_sort(vector<int> &v)
{
	int tmp, i, change;
	
	do
	{
		change = 0;
		i = v.size() - 1;
		
		do
		{
			i--;
			
			if (v[i + 1] < v[i])
			{
				tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
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

	b_sort(v);

	cout << endl << endl << "After: ";
	for (i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}