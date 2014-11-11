#include <string>
#include <vector>
#include <math.h>

using namespace std;

namespace crypto {
	namespace caesar {
		vector<string> default_alphabets = {
			"abcdefghijklmnopqrstuvwxyz",
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"0123456789"
		};

		void caesar(string &s, const int k, const vector<string> &alphabets)
		{
			char c;

			for (string::iterator iter = s.begin(); iter != s.cend(); iter++)
			{
				c = *iter;

				for (auto alphabet = alphabets.begin(); alphabet != alphabets.cend(); alphabet++)
				{
					char first = (*alphabet).front(), last = (*alphabet).back();

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

		void encode(string &s, const int k, const vector<string> &alphabets)
		{
			caesar(s, k, alphabets);
		}

		void encode(string &s, const vector<string> &alphabets)
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

		void decode(string &s, const int k, const vector<string> &alphabets)
		{
			caesar(s, -k, alphabets);
		}

		void decode(string &s, const vector<string> &alphabets)
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