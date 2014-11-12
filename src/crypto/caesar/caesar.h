#ifndef CRYPTO_CAESAR_H
#define CRYPTO_CAESAR_H

#include <vector>
#include <string>

namespace crypto {
	namespace caesar {
		typedef std::vector<std::string> alphabets_t;

		void encode(std::string &s);
		void encode(std::string &s, const int k);
		void encode(std::string &s, const int k, const alphabets_t &alphabets);
		void encode(std::string &s, const alphabets_t &aplhabets);

		void decode(std::string &s);
		void decode(std::string &s, const int k);
		void decode(std::string &s, const int k, const alphabets_t &alphabets);
		void decode(std::string &s, const alphabets_t &aplhabets);
	}
}

#endif // CRYPTO_CAESAR_H