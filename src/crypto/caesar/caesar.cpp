#include <string>
#include <vector>
#include <math.h>
#include "caesar.h"

using namespace std;

namespace crypto {
	namespace caesar {
		alphabets_t default_alphabets = {
			"abcdefghijklmnopqrstuvwxyz",
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"0123456789"
		};

		void caesar(string &s, const int k, const alphabets_t &alphabets)
		{
			char c, first, last;

			for (string::iterator iter = s.begin(); iter != s.cend(); iter++)
			{
				c = *iter;

				for (alphabets_t::const_iterator alphabet = alphabets.cbegin(); alphabet != alphabets.cend(); alphabet++)
				{
					first = (*alphabet).front();
					last = (*alphabet).back();

					if (c >= first && c <= last)
					{
						c -= first;
						c += k;
						c = c < 0 ? (*alphabet).length() - fabs(c) : fmod(c, (*alphabet).length());
						c += first;
						break;
					}
				}

				*iter = c;
			}
		}

		void encode(string &s, const int k, const alphabets_t &alphabets)
		{
			caesar(s, k, alphabets);
		}

		void encode(string &s, const alphabets_t &alphabets)
		{
			caesar(s, 3, alphabets);
		}

		void encode(string &s, const int k)
		{
			caesar(s, k, default_alphabets);
		}

		void encode(string &s)
		{
			caesar(s, 3, default_alphabets);
		}

		void decode(string &s, const int k, const alphabets_t &alphabets)
		{
			caesar(s, -k, alphabets);
		}

		void decode(string &s, const alphabets_t &alphabets)
		{
			caesar(s, -3, alphabets);
		}

		void decode(string &s, const int k)
		{
			caesar(s, -k, default_alphabets);
		}

		void decode(string &s)
		{
			caesar(s, -3, default_alphabets);
		}
	}
}