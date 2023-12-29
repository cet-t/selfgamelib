from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util import Padding
from hashlib import pbkdf2_hmac


class MyAES:
    def __init__(self, password: str) -> None:
        self.__salt = get_random_bytes(16)
        self.__password = password
        self.__iv = get_random_bytes(16)

    def en(self, src) -> bytes:

        key = pbkdf2_hmac(
            'sha256', bytes(self.__password, encoding='utf-8'),
            self.__salt,
            50000,
            int(128 / 8)
        )

        aes = AES.new(key, AES.MODE_CBC, self.__iv)
        data = Padding.pad(src.encode('utf-8'), AES.block_size, 'pkcs7')
        dst = aes.encrypt(data)
        return dst

    def de(self, src) -> bytes:
        key = pbkdf2_hmac(
            'sha256',
            bytes(self.__password, encoding='utf-8'),
            self.__salt,
            50000,
            int(128 / 8)
        )
        aes = AES.new(key, AES.MODE_CBC, self.__iv)
        return aes.decrypt(src)
