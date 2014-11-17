#include <string>

namespace crypto {
	namespace cipher {
		void rot5(std::string &s)
		{
			for(std::string::iterator c = s.begin(); c != s.cend(); c++)
			{
				if (*c >= '0' && *c < '0' + 5) *c += 5;
				else if (*c > '9' - 5 && *c <= '9') *c -= 5;
			}
		}
	}
}