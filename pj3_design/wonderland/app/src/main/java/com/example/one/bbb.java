package com.example.one;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class bbb {
    private static byte[] iv={1,2,3,4,5,6,7,8};
    public static String hhh(String origin) {
        return en(origin);
    }
    public static String en(String str) {
        char[] back=new char[str.length()];
        for(int i=0;i<str.length()-1;i++){
            back[i]=(char)(str.charAt(i+1)-i);
        }
        back[str.length()-1]=(char)(str.charAt(0)-(str.length()-1));
        String s = new String(back);
        return s;

    }
    public static String door(String e1,String e2,String e3,String e4) throws Exception{
        IvParameterSpec zeroIv = new IvParameterSpec(iv);
        SecretKeySpec key = new SecretKeySpec(e4.getBytes(), e1);
        Cipher cipher = Cipher.getInstance(e2);
        cipher.init(Cipher.ENCRYPT_MODE, key, zeroIv);
        byte[] encryptedData = cipher.doFinal(e3.getBytes());
        return ddd.encode(encryptedData);

    }

}
