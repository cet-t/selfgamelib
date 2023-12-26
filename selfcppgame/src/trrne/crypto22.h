#ifndef CRYPTO22_H
#define CRYPTO22_H

#include <iostream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/secblock.h>
#include <string>

using namespace std;
using namespace CryptoPP;

namespace trrne
{
	class crypto22
	{
	private:
		SecByteBlock key, iv;

	public:
		crypto22() noexcept
			: key(SecByteBlock(AES::DEFAULT_KEYLENGTH)),
			  iv(SecByteBlock(AES::BLOCKSIZE)) {}

		char *en(const char *src) noexcept
		{
			auto dst = "";
		}

		char *de(const char *src) noexcept
		{
			return nullptr;
		}

		string en(const string src) const noexcept
		{
			string dst = "";
			CBC_Mode<AES>::Encryption e;
			e.SetKeyWithIV(key, key.size(), iv);
			auto sink = new StringSink(dst);
			auto filter = new StreamTransformationFilter(e, sink);
			StringSource ss(src, true, filter);
			return dst;
		}

		string de(const string src) const noexcept
		{
			string dst = "";
			CBC_Mode<AES>::Decryption d;
			d.SetKeyWithIV(key, key.size(), iv);
			auto sink = new StringSink(dst);
			auto filter = new StreamTransformationFilter(d, sink);
			StringSource ss(src, true, filter);
			return dst;
		}
	};
}

#endif CRYPTO22_H
