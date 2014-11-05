/**
 * Sorting integers - insertion sort method.
 */
#include <vector>
#include <algorithm>

namespace sort {
	void insertion(std::vector<int> &v)
	{
		unsigned int i, j;
		int k;

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
} // namespace