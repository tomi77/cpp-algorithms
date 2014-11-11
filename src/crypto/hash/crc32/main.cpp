#include <iostream>
#include <fstream>
#include <string>
#include "crc32.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		cout << argv[0] << " file" << endl;
		return 1;
	}

	ifstream file(argv[1], ios::in | ios::binary | ios::ate);
	if (!file.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		return 1;
	}

	streampos size = file.tellg();
	char * memblock = new char[size];

	file.seekg(0, ios::beg);
	file.read(memblock, size);
	file.close();

	unsigned int crc32 = crypto::hash::crc32(memblock);

	cout.setf(ios::hex, ios::basefield);
	cout << crc32 << endl;

	delete[] memblock;

	return 0;
}