/**
 * Sorting integers - counting sort method.
 */
#include <vector>
#include <algorithm>

using namespace std;

namespace sort {
	void counting(vector<int> &v)
	{
		vector<int> tmp;
		unsigned int i, size;

		for (i = 0, size = v.size(); i < size; ++i)
		{
			if (tmp.size() < v[i])
			{
				tmp.resize(v[i] + 1);
			}
			tmp[v[i]]++;
		}

		v.clear();

		for (i = 0, size = tmp.size(); i < size; ++i)
		{
			if (tmp[i] > 0)
			{
				v.insert(v.end(), tmp[i], i);
			}
		}
	}
} // namespace