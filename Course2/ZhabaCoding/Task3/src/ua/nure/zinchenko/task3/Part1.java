package ua.nure.zinchenko.task3;

import java.security.SecureRandom;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part1 {
    private static final String EOL = System.lineSeparator();
    private static final String FILE_NAME = "part1.txt";

    public static void main(String[] args){
        System.out.println(convert1(Util.readFile(FILE_NAME)));
        System.out.println(convert2(Util.readFile(FILE_NAME)));
        System.out.println(convert3(Util.readFile(FILE_NAME)));
        System.out.println(convert4(Util.readFile(FILE_NAME)));
    }

    public static String convert1(String data) {
        String regex = ";.+[\\w\\s\\p{L}];";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(data);

        matcher.find();

        StringBuilder result = new StringBuilder(matcher.replaceAll(": "));
        result.delete(0,result.indexOf(EOL) + EOL.length());

        return result.toString();
    }

    public static String convert2(String data) {
        String regex = ".+[\\w\\s\\p{L}];";
        String swapRegex = ".+[\\w\\p{L}]\\s";
        String emailRegex = ";[\\w-+]+(\\.[\\w]+)*@[\\w-]+(\\.[\\w]+)*(\\.[a-z]{2,})";

        Pattern emailPattern = Pattern.compile(emailRegex);
        Matcher emailMatcher = emailPattern.matcher(data);

        StringBuilder result = new StringBuilder(data);

        int offset = 0;

        while (emailMatcher.find()){
            int start = emailMatcher.start();
            int end = emailMatcher.end();
            String email = " (email: " + data.substring(start+1,end) + ")";
            result.replace(start + offset, end + offset, email);
            offset += 9;
        }

        result.delete(0,result.indexOf(EOL) + EOL.length());

        result = new StringBuilder(result.toString().replaceAll(regex,""));

        Pattern swapPattern = Pattern.compile(swapRegex);
        Matcher swapMatcher = swapPattern.matcher(result);

        while(swapMatcher.find()){
            int start = swapMatcher.start();
            int end = swapMatcher.end() - 1;
            result.replace(start,end,swapWords(result.substring(start,end)));
        }

        return result.toString();
    }

    public static String convert3(String data) {
        int nstart = 0;
        StringBuilder result = new StringBuilder();


        String regex = "@[\\w-]+(\\.[\\w]+)*(\\.[a-z]{2,})";

        data = data.substring(data.indexOf(EOL) + EOL.length());

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(data);

        while (matcher.find()){
            int start = matcher.start();
            int end = matcher.end();
            String dom = data.substring(start+1,end);
            String login = data.substring(nstart,data.indexOf(';', nstart));
            if(!result.toString().contains(dom)){
                result.append(dom).append(" ==> ").append(login).append(EOL);
            }else{
                int it = result.indexOf(EOL, result.indexOf(dom));
                result.insert(it, ", " + login);
            }

            nstart = end + EOL.length();
        }
        result.delete(result.length() - EOL.length(),result.length());
        return result.toString();
    }

    public static String convert4(String data) {
        StringBuilder result = new StringBuilder(data);

        String regex = "@[\\w-]+(\\.[\\w]+)*(\\.[a-z]{2,})";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(data);

        int offset = 0;
        int randomNumLength = 5;
        final int randBegin = 1000;
        final int randEnd = 8999;
        SecureRandom r = new SecureRandom();

        while (matcher.find()) {
            int end = matcher.end() + offset;
            int rand = randBegin + r.nextInt(randEnd);
            result.insert(end,";" + rand);
            offset += randomNumLength;
        }
        result.insert(result.indexOf(EOL),";Password");
        return result.append(EOL).toString();
    }

    private static String swapWords(String words){
        StringBuilder result = new StringBuilder(words);
        int spaceIn = result.indexOf(" ");
        result.append(" ").append(result.substring(0,spaceIn));
        result.delete(0,spaceIn+1);
        return result.toString();
    }
}
