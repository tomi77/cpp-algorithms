/**
 * Sorting integers - quick sort method.
 */
#include <vector>
#include <algorithm>

using namespace std;

void quicksort(vector<int>& v, const int x, const int y)
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

void quicksort(vector<int>& v)
{
	quicksort(v, 0, v.size() - 1);
}