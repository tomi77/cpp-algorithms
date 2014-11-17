#include <string>

namespace crypto {
	namespace cipher {
		void rot47(std::string &s)
		{
			for(std::string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if (*c >= 33 && *c < 33 + 47) *c += 47;
				else if (*c > 126 - 47 && *c <= 126) *c -= 47;
			}
		}
	}
}