#include <string>
#include <math.h>

using namespace std;

namespace crypto {
	namespace caesar {
		void encode(string &s, int k)
		{
			char c;
			string::iterator iter = s.begin();

			while (iter != s.cend())
			{
				c = *iter;

				if (c >= 'a' && c <= 'z')
				{
					c -= 'a';
					c += k;
					c = fmod(c, 'z' - 'a' + 1);
					c += 'a';
				}
				else if (c >= 'A' && c <= 'Z')
				{
					c -= 'A';
					c += k;
					c = fmod(c, 'Z' - 'A' + 1);
					c += 'A';
				}
				else if (c >= '0' && c <= '9')
				{
					c -= '0';
					c += k;
					c = fmod(c, '9' - '0' + 1);
					c += '0';
				}

				*iter = c;

				iter++;
			}
		}

		void encode(string &s)
		{
			encode(s, 3);
		}

		void decode(string &s, int k)
		{
			char c;
			string::iterator iter = s.begin();

			while (iter != s.cend())
			{
				c = *iter;

				if (c >= 'a' && c <= 'z')
				{
					c -= 'a';
					c -= k;
					if (c < 0)
						c = 'z' - 'a' + 1 - fabs(c);
					c += 'a';
				}
				else if (c >= 'A' && c <= 'Z')
				{
					c -= 'A';
					c -= k;
					if (c < 0)
						c = 'Z' - 'A' + 1 - fabs(c);
					c += 'A';
				}
				else if (c >= '0' && c <= '9')
				{
					c -= '0';
					c -= k;
					if (c < 0)
						c = '9' - '0' + 1 - fabs(c);
					c += '0';
				}

				*iter = c;

				iter++;
			}
		}

		void decode(string &s)
		{
			decode(s, 3);
		}
	}
}