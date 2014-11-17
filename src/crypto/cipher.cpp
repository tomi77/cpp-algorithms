#include <string>
#include <vector>
#include <cmath>
#include "cipher.h"

using namespace std;

#define default_alphabets alphabets_t { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789" }

namespace crypto {
	namespace cipher {
		void rot5(string &s)
		{
			for(string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if (*c >= '0' && *c < '0' + 5) *c += 5;
				else if (*c > '9' - 5 && *c <= '9') *c -= 5;
			}
		}

		void rot13(string &s)
		{
			for(string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if ((*c >= 'A' && *c < 'A' + 13) || (*c >= 'a' && *c < 'a' + 13)) *c += 13;
				else if ((*c > 'Z' - 13 && *c <= 'Z') || (*c > 'z' - 13 && *c <= 'z')) *c -= 13;
			}
		}

		void rot18(string &s)
		{
			for(string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if ((*c >= 'A' && *c < 'A' + 13) || (*c >= 'a' && *c < 'a' + 13)) *c += 13;
				else if ((*c > 'Z' - 13 && *c <= 'Z') || (*c > 'z' - 13 && *c <= 'z')) *c -= 13;
				else if (*c >= '0' && *c < '0' + 5) *c += 5;
				else if (*c > '9' - 5 && *c <= '9') *c -= 5;
			}
		}

		void rot47(string &s)
		{
			for(string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if (*c >= 33 && *c < 33 + 47) *c += 47;
				else if (*c > 126 - 47 && *c <= 126) *c -= 47;
			}
		}

		void transposition(string &s, const int k, const alphabets_t &alphabets)
		{
			char c, first;

			for (string::iterator iter = s.begin(); iter != s.cend(); iter++)
			{
				c = *iter;

				for (alphabets_t::const_iterator alphabet_iter = alphabets.cbegin(); alphabet_iter != alphabets.cend(); alphabet_iter++)
				{
					string alphabet = *alphabet_iter;

					if (alphabet.find(c) != string::npos)
					{
						first = alphabet.front();

						c -= first;
						c += k;
						c = fmod(c + alphabet.length(), alphabet.length());
						c += first;
						break;
					}
				}

				*iter = c;
			}
		}

		namespace caesar {
			void encode(string &s)
			{
				transposition(s, 3, default_alphabets);
			}

			void decode(string &s)
			{
				transposition(s, -3, default_alphabets);
			}
		}
	}
}