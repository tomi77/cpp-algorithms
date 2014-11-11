#ifndef CRYPTO_CAESAR_H
#define CRYPTO_CAESAR_H

#include <vector>
#include <string>

namespace crypto {
	namespace caesar {
		void encode(std::string &s);
		void encode(std::string &s, const int k);
		void encode(std::string &s, const int k, const std::vector<std::string> &alphabets);
		void encode(std::string &s, const std::vector<std::string> &aplhabets);

		void decode(std::string &s);
		void decode(std::string &s, const int k);
		void decode(std::string &s, const int k, const std::vector<std::string> &alphabets);
		void decode(std::string &s, const std::vector<std::string> &aplhabets);
	}
}

#endif // CRYPTO_CAESAR_H