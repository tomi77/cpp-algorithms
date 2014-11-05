/**
 * Sorting integers - bubble method.
 */
#include <vector>
#include <algorithm>

namespace sort {
	void bubble(std::vector<int> &v)
	{
		int i;
		bool change;

		do
		{
			change = false;
			i = v.size() - 1;

			do
			{
				--i;
				if (v[i + 1] < v[i])
				{
					std::swap(v[i], v[i + 1]);
					change = true;
				}
			}
			while (i != 0);
		}
		while (change);
	}
} // namespace