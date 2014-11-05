/**
 * Sorting integers - bubble method.
 */
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