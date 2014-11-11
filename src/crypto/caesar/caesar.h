#ifndef CRYPTO_CAESAR_H
#define CRYPTO_CAESAR_H

namespace crypto {
	namespace caesar {
		void encode(std::string &s);
		void encode(std::string &s, int k);

		void decode(std::string &s);
		void decode(std::string &s, int k);
	}
}

#endif // CRYPTO_CAESAR_H