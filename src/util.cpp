#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> &v)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void fillVector(vector<int> &v, const int size)
{
	srand(time(0));

	for (int i = 0; i < size; ++i)
	{
		v.push_back(rand() % size);
	}
}