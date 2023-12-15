#ifndef CRYPTO22_H
#define CRYPTO22_H

#include <iostream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/secblock.h>
#include <string.h>

using namespace std;
using namespace CryptoPP;

namespace trrne {
	class crypto22 {
	private:
		SecByteBlock key, iv;
	public:
		crypto22() noexcept;
		char *en(char *src) noexcept;
		char *de(char *src) noexcept;
		string en(const string src) const noexcept;
		string de(const string src) const noexcept;
	};
}

#endif CRYPTO22_H

