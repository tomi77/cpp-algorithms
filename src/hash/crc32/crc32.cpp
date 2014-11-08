#include <string>

#define P 0x04c11db7

using namespace std;

namespace hash {
	unsigned int crc32_tab[256];
	bool crc32_tab_calculated = false;

	unsigned int mirror_bits(unsigned int l, const int nbits)
	{
		unsigned int result = 0;

		for (int i = 1; i <= nbits; ++i)
		{
			if (l & 1)
			{
				result |= 1 << (nbits - i);
			}
			l >>= 1;
		}

		return result;
	}

	void init_crc32_tab(void)
	{
		for (int i = 0; i < 256; ++i)
		{
			crc32_tab[i] = mirror_bits(i, 8) << 24;

			for (int j = 0; j < 8; ++j)
			{
				crc32_tab[i] = ((crc32_tab[i] & (unsigned)(1 << 31)) != 0) ? (crc32_tab[i] << 1) ^ P : crc32_tab[i] << 1;
			}

			crc32_tab[i] = mirror_bits(crc32_tab[i], 32);
		}
		crc32_tab_calculated = true;
	}

	unsigned int crc32(const char * str)
	{
		if (!crc32_tab_calculated) init_crc32_tab();

		unsigned int i, crc = 0xffffffff; // 2^32 - 1
		size_t l;

		for (i = 0, l = char_traits<char>::length(str); i < l; ++i)
		{
			crc = (crc >> 8) ^ crc32_tab[(crc & 0xff) ^ (unsigned char)str[i]];
		}
		crc ^= 0xffffffff;

		return crc;
	}
}