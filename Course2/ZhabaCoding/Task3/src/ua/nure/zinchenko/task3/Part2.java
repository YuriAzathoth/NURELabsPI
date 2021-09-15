package ua.nure.zinchenko.task3;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part2 {
    private static final String EOL = System.lineSeparator();

    public static void main(String[] args){
        System.out.println(convert(Util.readFile("part2.txt")));
    }

    public static String convert(String data) {

        String regex = "[\\w\\p{L}]+";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(data);

        int max = 0;
        int min = 0;
        StringBuilder maxString = new StringBuilder();
        StringBuilder minString = new StringBuilder();
        StringBuilder result = new StringBuilder("Min: ");

        while(matcher.find()){
            int begin = matcher.start();
            int end = matcher.end();
            String word = data.substring(begin, end);
            if(min == 0){
                min = word.length();
            }

            if(word.length() < min){
                min = word.length();
                minString = new StringBuilder(word);
            }else if(word.length() == min && !minString.toString().contains(word)){
                minString.append(", ").append(word);
            }

            if(word.length() > max){
                max = word.length();
                maxString = new StringBuilder(word);
            }else if(word.length() == max && !maxString.toString().contains(word)){
                maxString.append(", ").append(word);
            }
        }

        result.append(minString).append(EOL).append("Max: ").append(maxString);

        return result.toString();
    }
}
