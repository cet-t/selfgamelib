using System.Security.Cryptography;
using System.Text;

namespace trrne;

public sealed class MyRSA(RSAEncryptionPadding padding)
{
    readonly static RSA rsa = RSA.Create();
    readonly RSAEncryptionPadding padding = padding;

    public byte[] En(byte[] src) => rsa.Encrypt(src, padding);
    public byte[] En(string src) => rsa.Encrypt(Encoding.UTF8.GetBytes(src), padding);
    public byte[] De(byte[] src) => rsa.Decrypt(src, padding);
    public string De2Str(byte[] src) => Encoding.UTF8.GetString(rsa.Decrypt(src, padding));

    public static RSAEncryptionPadding PKCS1 => RSAEncryptionPadding.Pkcs1;

    public static byte[] En(byte[] src, RSAEncryptionPadding? padding = null)
    => rsa.Encrypt(src, padding is null ? PKCS1 : padding);

    public static byte[] En(string src, RSAEncryptionPadding? padding = null)
    => rsa.Encrypt(Encoding.UTF8.GetBytes(src), padding is null ? PKCS1 : padding);

    public static string En2Str(byte[] src, RSAEncryptionPadding? padding = null)
    => Encoding.UTF8.GetString(rsa.Encrypt(src, padding is null ? PKCS1 : padding));

    public static byte[] De(byte[] src, RSAEncryptionPadding? padding = null)
    => rsa.Decrypt(src, padding is null ? PKCS1 : padding);

    public static string De2Str(byte[] src, RSAEncryptionPadding? padding = null)
    => Encoding.UTF8.GetString(rsa.Decrypt(src, padding is null ? PKCS1 : padding));
}