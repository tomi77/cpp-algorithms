#include <string>

namespace crypto {
	namespace cipher {
		void rot13(std::string &s)
		{
			for(std::string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if ((*c >= 'A' && *c < 'A' + 13) || (*c >= 'a' && *c < 'a' + 13)) *c += 13;
				else if ((*c > 'Z' - 13 && *c <= 'Z') || (*c > 'z' - 13 && *c <= 'z')) *c -= 13;
			}
		}
	}
}