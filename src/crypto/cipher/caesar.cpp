#include <iostream>
#include <string>
#include "cipher.h"

using namespace std;

int main(int argc, char const *argv[])
{
	bool decode = false;
	string s;

	if (argc > 1)
	{
		decode = string(argv[1]).compare("-d") == 0;
	}

	do
	{
		getline(cin, s);

		if (decode)
			crypto::cipher::caesar::decode(s);
		else
			crypto::cipher::caesar::encode(s);

		cout << s << endl;
	} while (!cin.eof());

	return 0;
}