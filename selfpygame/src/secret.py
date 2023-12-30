from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util import Padding
from hashlib import pbkdf2_hmac


class MyAES:
    def __init__(self, password, size=16) -> None:
        self.__salt = get_random_bytes(16)
        self.__password = password
        self.__iv = get_random_bytes(16)
        self.__size = size

    def en(self, src):

        key = pbkdf2_hmac(
            'sha256', bytes(self.__password, encoding='utf-8'),
            self.__salt,
            50000,
            self.__size
        )

        data = Padding.pad(src.encode('utf-8'), AES.block_size, 'pkcs7')
        return AES.new(key, AES.MODE_CBC, self.__iv).encrypt(data)

    def de(self, src):
        key = pbkdf2_hmac(
            'sha256',
            bytes(self.__password, encoding='utf-8'),
            self.__salt,
            50000,
            self.__size
        )
        return AES.new(key, AES.MODE_CBC, self.__iv).decrypt(src)
