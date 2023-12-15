#include "crypto22.h"

trrne::crypto22::crypto22() noexcept
	: key(SecByteBlock(AES::DEFAULT_KEYLENGTH)),
	iv(SecByteBlock(AES::BLOCKSIZE)) { }

char *trrne::crypto22::en(char *src) noexcept {
	return nullptr;
}

char *trrne::crypto22::de(char *src) noexcept {
	return nullptr;
}

string trrne::crypto22::en(const string src) const noexcept {
	string dst = "";
	CBC_Mode<AES>::Encryption e;
	e.SetKeyWithIV(key, key.size(), iv);
	auto sink = new StringSink(dst);
	auto filter = new StreamTransformationFilter(e, sink);
	StringSource ss(src, true, filter);
	return dst;
}

string trrne::crypto22::de(const string src) const noexcept {
	string dst = "";
	CBC_Mode<AES>::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
	auto sink = new StringSink(dst);
	auto filter = new StreamTransformationFilter(d, sink);
	StringSource ss(src, true, filter);
	return dst;
}
