package ua.nure.zinchenko.task4;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class WordContainer {
    private static List<Word> list;
    private static final String EOL = System.lineSeparator();

    public static void main(String[] args){
        list = new ArrayList<>();

        StringBuilder result = new StringBuilder();
        Scanner reader = new Scanner(System.in);
        while(true){
            try {
                String line = reader.nextLine();
                if("stop".equals(line) || "Stop".equals(line)){
                    reader.close();
                    break;
                }
                if(line.contains("stop") || line.contains("Stop")){
                    int index = !line.contains("stop") ? line.indexOf("Stop") : line.indexOf("stop");
                    line = line.substring(0,index);
                }
                result.append(line).append(" ");
            }catch (NoSuchElementException e){
                break;
            }
        }

        String[] words = result.toString().split("\\s+");

        getWordsFrequency(words);

        list.sort(Word::compareTo);
        System.out.println(getFrequencyString());
    }

    private static void getWordsFrequency(String[] words){
        for(String part : words){
            Word word = new Word(part,frequency(part,words));
            if(!containsWord(part)){
                list.add(word);
            }
        }
    }

    private static boolean containsWord(String word){
        for(Word part : list){
            if(word.equals(part.getContent())){
                return true;
            }
        }
        return false;
    }

    private static String getFrequencyString(){
        StringBuilder result = new StringBuilder();

        for(Word part : list){
            result.append(part.getContent()).append(" : ").append(part.getFrequency()).append(EOL);
        }

        return result.delete(result.length() - EOL.length(),result.length()).toString();
    }

    private static int frequency(String word,String[] words){
        int result = 0;
        for(String part : words){
            if(part.equals(word)){
                result++;
            }
        }
        return result;
    }
}
