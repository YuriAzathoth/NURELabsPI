package ua.nure.zinchenko.task3;

import java.util.Locale;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part3 {

    public static void main(String[] args){
        System.out.println(convert(Util.readFile("part3.txt")));
    }

    public static String convert(String input) {
        String regex = "[\\w\\p{L}]+";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);

        StringBuilder result = new StringBuilder(input);

        while(matcher.find()){
            int start = matcher.start();
            int end = matcher.end();

            if(end - start >= 3){
                if(Character.isUpperCase(result.charAt(start))){
                    result.replace(start,start+1,result.substring(start,start+1).toLowerCase(Locale.getDefault()));
                }else{
                    result.replace(start,start+1,result.substring(start,start+1).toUpperCase(Locale.getDefault()));
                }
            }
        }

        return result.toString();
    }
}
