#include <string>
#include <iostream>
#include "rot5.h"

using namespace std;
using namespace crypto::cipher;

int main(int argc, char const *argv[])
{
	string s;

	while (!cin.eof())
	{
		getline(cin, s);
		rot5(s);
		cout << s << endl;
	}

	return 0;
}