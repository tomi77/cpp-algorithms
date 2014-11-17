#include <string>
#include <iostream>
#include "cipher.h"

using namespace std;
using namespace crypto::cipher;

int main(int argc, char const *argv[])
{
	string s;

	while (!cin.eof())
	{
		getline(cin, s);
		rot18(s);
		cout << s << endl;
	}

	return 0;
}