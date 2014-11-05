/**
 * Sorting integers - quick sort method.
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace sort {
	void counting(vector<int> &v)
	{
		vector<int> tmp;
		unsigned int i, j;
		
		for (i = 0; i < v.size(); ++i)
		{
			if (tmp.size() < v[i])
			{
				tmp.resize(v[i] + 1);
			}
			tmp[v[i]]++;
		}

		v.clear();

		for (i = 0; i < tmp.size(); ++i)
		{
			for (j = 0; j < tmp[i]; ++j)
			{
				v.push_back(i);
			}
		}
	}
}