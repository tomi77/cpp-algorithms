/**
 * Sorting integers - bubble method.
 */
#include <vector>
#include <algorithm>

namespace sort {
	void bubble(std::vector<int> &v)
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
					std::swap(v[i], v[i + 1]);
					change = 1;
				}
			}
			while (i != 0);
		}
		while (change != 0);
	}
} // namespace