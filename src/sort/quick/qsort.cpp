/**
 * Sorting integers - quick sort method.
 */
#include <vector>
#include <algorithm>

namespace sort {
	void quick(std::vector<int> &v, const int x, const int y)
	{
		int i = x, j = y, k = v[std::div(x + y, 2).quot];

		do
		{
			while (v[i] < k) ++i;
			while (k < v[j]) --j;
			if (i <= j)
			{
				std::swap(v[i++], v[j--]);
			}
		}
		while (i <= j);
		if (x < j) quick(v, x, j);
		if (i < y) quick(v, i, y);
	}

	void quick(std::vector<int> &v)
	{
		quick(v, 0, v.size() - 1);
	}
} // namespace