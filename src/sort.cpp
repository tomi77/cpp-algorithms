#include <vector>
#include <algorithm>

using namespace std;

namespace sort {
	/**
	 * Sorting integers - bubble method.
	 */
	void bubble(vector<int> &v)
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

	/**
	 * Sorting integers - counting sort method.
	 */
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

	/**
	 * Sorting integers - insertion sort method.
	 */
	void insertion(vector<int> &v)
	{
		unsigned int i, j, size;
		int k;

		for (i = 1, size = v.size(); i < size; ++i)
		{
			j = i;
			k = v[i];

			while (j > 0 && v[j - 1] > k)
			{
				v[j] = v[j - 1];
				--j;
			}
			v[j] = k;
		}
	}

	/**
	 * Sorting integers - quick sort method.
	 */
	void quick(vector<int> &v, const int x, const int y)
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

	void quick(vector<int> &v)
	{
		quick(v, 0, v.size() - 1);
	}
} // namespace