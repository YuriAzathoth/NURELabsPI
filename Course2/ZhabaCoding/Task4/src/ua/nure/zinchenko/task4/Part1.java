package ua.nure.zinchenko.task4;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part1 {
    public static void main(String[] args){
        initPart1();
    }

    private static void initPart1(){
        String input = Util.readFile("part1.txt");
        Scanner scanner = new Scanner(System.in);

        while(true){
            String line = scanner.nextLine();
            if("stop".equals(line) || "Stop".equals(line)){
                scanner.close();
                break;
            }
            switch (line){
                case "Latn":
                    System.out.print(line + ": ");
                    System.out.println(getLatin(input));
                    break;

                case "Cyrl":
                    System.out.print(line + ": ");
                    System.out.println(getCyril(input));
                    break;

                default:
                    System.out.print(line + ": ");
                    System.out.println("Incorrect input");
                    break;
            }
        }
    }

    private static String getLatin(String input){
        Pattern pattern = Pattern.compile("[\\w\\d]+");
        Matcher matcher = pattern.matcher(input);

        StringBuilder result = new StringBuilder();
        while(matcher.find()){
            int start = matcher.start();
            int end = matcher.end();
            result.append(input, start, end).append(" ");
        }

        return result.delete(result.length()-1,result.length()).toString();
    }

    private static String getCyril(String input){
        Pattern pattern = Pattern.compile("[а-яёіїєА-ЯЁІЇЄ'\\d]+");
        Matcher matcher = pattern.matcher(input);

        StringBuilder result = new StringBuilder();
        while(matcher.find()){
            int start = matcher.start();
            int end = matcher.end();
            result.append(input, start, end).append(" ");
        }

        return result.delete(result.length()-1,result.length()).toString();
    }

}
