package ua.nure.zinchenko.task3;

import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;
import java.util.Locale;

public class Part4 {

    public static void main(String[] args){
        try{
            System.out.println(hash("adf", "MD5"));
            System.out.println(hash("asdf", "SHA-256"));
        }catch(NoSuchAlgorithmException e){
            e.printStackTrace();
        }
    }

    public static String hash(String input, String alg) throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance(alg);
        digest.update(input.getBytes());
        byte[] hash = digest.digest();
        StringBuilder result = new StringBuilder();
        for (byte symbol : hash) {
            String hexNum = Integer.toHexString(symbol);
            if(hexNum.length() > 2){
                hexNum = hexNum.substring(hexNum.length()-2);
            }
            if(hexNum.length() == 1){
                result.append("0");
            }
            result.append(hexNum);
        }
        return result.toString().toUpperCase(Locale.getDefault());
    }
}
