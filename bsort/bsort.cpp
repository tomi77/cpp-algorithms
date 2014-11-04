#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void b_sort(vector<int> &tab)
{
	int tmp, i, change;
	
	do
	{
		change = 0;
		i = tab.size() - 1;
		
		do
		{
			i--;
			
			if (tab[i + 1] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				change = 1;
			}
		}
		while (i != 0);
	}
	while (change != 0);
}

int main(int argc, char const *argv[])
{
	int count, i, n;
	vector<int> tab;

	cout << "How many:";
	cin >> count;
	
	for (i = 0; i < count; ++i)
	{
		tab.push_back(rand() % count);
	}

	cout << endl << "Before:";
	for (i = 0; i < tab.size(); ++i)
	{
		cout << endl << tab[i];
	}

	b_sort(tab);

	cout << endl << endl << "After:";
	for (i = 0; i < tab.size(); ++i)
	{
		cout << endl << tab[i];
	}

	return 0;
}