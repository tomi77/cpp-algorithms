#ifndef CRYPTO_CIPHER_TRANSPOSITION_H
#define CRYPTO_CIPHER_TRANSPOSITION_H

#include <vector>
#include <string>

namespace crypto {
	namespace cipher {
		typedef std::vector<std::string> alphabets_t;

		void transposition(std::string &s, const int k, const alphabets_t &alphabets);
	}
}

#endif // CRYPTO_CIPHER_TRANSPOSITION_H