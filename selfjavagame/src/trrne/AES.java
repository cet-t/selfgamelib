package trrne;

import java.nio.charset.StandardCharsets;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;

public class AES implements IEncryption {
    final byte[] key;

    public AES() throws NoSuchAlgorithmException, NoSuchPaddingException {
        key = "0123456789012345".getBytes(StandardCharsets.UTF_8);
        if (key.length != 16) {
            System.out.println("key length: " + key.length);
            throw new IllegalArgumentException("nagasa okasii");
        }
    }

    public byte[] Encrypt(byte[] $src)
            throws NoSuchAlgorithmException, InvalidKeyException, IllegalBlockSizeException, BadPaddingException,
            NoSuchPaddingException {
        Key spec = new SecretKeySpec(this.key, "AES");
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, spec);
        return cipher.doFinal($src);
    }

    public byte[] Encrypt(String $src)
            throws InvalidKeyException, NoSuchAlgorithmException, IllegalBlockSizeException, BadPaddingException,
            NoSuchPaddingException {
        return Encrypt($src.getBytes());
    }

    public byte[] Decrypt(byte[] $src) throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException {
        Key spec = new SecretKeySpec(this.key, "AES");
        Cipher cipher = Cipher.getInstance(spec.getAlgorithm() + "/CBC/PKCS5Padding");
        cipher.init(Cipher.DECRYPT_MODE, spec);
        return cipher.doFinal($src);
    }

    public String DecryptToString(byte[] $src) throws InvalidKeyException, NoSuchAlgorithmException,
            NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException {
        return new String(Decrypt($src));
    }
}