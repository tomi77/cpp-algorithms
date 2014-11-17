#ifndef CRYPTO_CIPHER_ROT13_H
#define CRYPTO_CIPHER_ROT13_H

#include <string>

namespace crypto {
	namespace cipher {
		void rot13(std::string &s);
	}
}

#endif // CRYPTO_CIPHER_ROT13_H