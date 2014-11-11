#include <iostream>
#include <string>
#include "caesar.h"

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
		getline(std::cin, s);

		if (decode)
			crypto::caesar::decode(s);
		else
			crypto::caesar::encode(s);

		cout << s << endl;
	} while (!cin.eof());

	return 0;
}