#ifndef CRYPTO_CIPHER_CAESAR_H
#define CRYPTO_CIPHER_CAESAR_H

#include <vector>
#include <string>
#include "../cipher/transposition/transposition.h"

#define default_alphabets alphabets_t { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789" }

namespace crypto {
	namespace cipher {
		namespace caesar {
			void encode(std::string &s, const int k, const alphabets_t &alphabets)
			{
				transposition(s, k, alphabets);
			}

			void encode(std::string &s, const alphabets_t &alphabets)
			{
				transposition(s, 3, alphabets);
			}

			void encode(std::string &s, const int k)
			{
				transposition(s, k, default_alphabets);
			}

			void encode(std::string &s)
			{
				transposition(s, 3, default_alphabets);
			}

			void decode(std::string &s, const int k, const alphabets_t &alphabets)
			{
				transposition(s, -k, alphabets);
			}

			void decode(std::string &s, const alphabets_t &alphabets)
			{
				transposition(s, -3, alphabets);
			}

			void decode(std::string &s, const int k)
			{
				transposition(s, -k, default_alphabets);
			}

			void decode(std::string &s)
			{
				transposition(s, -3, default_alphabets);
			}
		}
	}
}

#endif // CRYPTO_CIPHER_CAESAR_H