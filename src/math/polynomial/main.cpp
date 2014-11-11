#include <vector>
#include <iostream>
#include "horner.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(-5);
	v.push_back(0);
	v.push_back(2);
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	double result = math::polynomial::eval(v, 1.5);

	cout << result << ' ' << 47.0 / 8.0 << endl;

	return 0;
}