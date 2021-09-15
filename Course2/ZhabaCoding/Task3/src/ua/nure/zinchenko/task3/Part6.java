package ua.nure.zinchenko.task3;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part6 {
    public static void main(String[] args){
        System.out.println(convert(Util.readFile("part6.txt")));
    }

    public static String convert(String input) {
        String regex = "[\\w\\p{L}]+";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);

        StringBuilder result = new StringBuilder(input);

        int i = 0;

        while(matcher.find()){
            int start = matcher.start();
            int end = matcher.end();
            String word = input.substring(start,end);

            if(quantity(input,word) > 1){
                result.insert(start + i,"_");
                ++i;
            }
        }

        return result.toString();
    }

    private static int quantity(String s,String p){
        int count = 0;
        String regex = "[\\w\\p{L}]+";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(s);

        while (matcher.find()){
            if(s.substring(matcher.start(),matcher.end()).equals(p)){
                ++count;
            }
        }

        return count;
    }
}
