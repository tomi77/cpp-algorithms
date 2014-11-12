#include <string>
#include <vector>
#include <math.h>
#include "transposition.h"

using namespace std;

namespace crypto {
	namespace cipher {
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
	}
}