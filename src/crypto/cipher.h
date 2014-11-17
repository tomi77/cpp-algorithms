#ifndef CRYPTO_CIPHER_H
#define CRYPTO_CIPHER_H

#include <string>
#include <vector>

typedef std::vector<std::string> alphabets_t;

namespace crypto {
	namespace cipher {
		void rot5(std::string &s);

		void rot13(std::string &s);

		void rot18(std::string &s);

		void rot47(std::string &s);

		void transposition(std::string &s, const int k, const alphabets_t &alphabets);

		namespace caesar {
			void encode(std::string &s);

			void decode(std::string &s);
		}
	}
}

#endif // CRYPTO_CIPHER_H