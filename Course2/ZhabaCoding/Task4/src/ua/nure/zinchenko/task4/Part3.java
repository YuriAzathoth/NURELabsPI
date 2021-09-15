package ua.nure.zinchenko.task4;

import java.util.Locale;
import java.util.ResourceBundle;
import java.util.Scanner;

public class Part3 {
    public static void main(String[] args){
        final String resBundleName = "resources";

        Scanner reader = new Scanner(System.in);

        while (true){
            Locale locale;
            ResourceBundle resBundle = ResourceBundle.getBundle(resBundleName);
            String in = reader.nextLine();

            String[] input = in.split("\\s+");

            if("Stop".equals(in) || "stop".equals(in)){
                break;
            }

            if(input.length != 2 || !resBundle.containsKey(input[0])){
                System.out.println("Incorrect input");
                continue;
            }

            if("en".equals(input[1])){
                locale = new Locale("en");
                resBundle = ResourceBundle.getBundle(resBundleName, locale);
            }else if("ru".equals(input[1])){
                locale = new Locale("ru");
                resBundle = ResourceBundle.getBundle(resBundleName, locale);
            }

            System.out.println(resBundle.getString(input[0]));
        }
    }
}
