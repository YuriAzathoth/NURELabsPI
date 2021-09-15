package ua.nure.zinchenko.task4;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.List;

public class Part4 {
    private static final String EOL = System.lineSeparator();

    public static void main(String[] args){
        String input = null;
        File outfile = new File("part4.txt");

        try {
            if (outfile.createNewFile()) {
                writeSorted(outfile);
            }
            input = Util.readFile("part4.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }

        if(input != null){
            String[] in = input.split(" ");

            List<Integer> nums = new ArrayList<>();
            for(String numStr : in){
                int numInt = Integer.parseInt(numStr);
                if(!nums.contains(numInt)){
                    nums.add(numInt);
                }
            }

            StringBuilder result = new StringBuilder("input ==> ").append(input).append(EOL).append("output ==> ");
            sort(nums, 0, nums.size() - 1);


            StringBuilder output = new StringBuilder();
            for(int num : nums){
                output.append(num).append(" ");
            }
            output.delete(output.length() - 1, output.length());

            File file = new File("part4_sorted.txt");

            try(FileWriter writer = new FileWriter(file)) {
                file.createNewFile();
                writeOut(writer, output.toString());

            } catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println(result.append(output).toString());
        }
    }

    private static void writeSorted(File file) {
        try (FileWriter writer = new FileWriter(file)) {
            writeToFile(writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void writeToFile(FileWriter writer) {
        try(BufferedWriter buffered = new BufferedWriter(writer)) {
            buffered.write(sortedString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sort(List<Integer> list, int begin, int end){
        if (begin < end) {
            int index = partition(list, begin, end);

            sort(list, begin, index - 1);
            sort(list, index + 1, end);
        }
    }

    private static String sortedString(){
        StringBuilder sorted = new StringBuilder();
        SecureRandom rand = new SecureRandom();

        for (int i = 0; i < 10; i++) {
            int rnd = rand.nextInt(50);
            sorted.append(rnd);
            if (i < 9) {
                sorted.append(" ");
            }
        }

        return sorted.toString();
    }

    private static void writeOut(FileWriter writer, String output){
        try (BufferedWriter buffered = new BufferedWriter(writer)) {
            buffered.write(output);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int partition(List<Integer> list, int begin, int end) {
        int origin = list.get(end);
        int i = (begin-1);

        for (int j = begin; j < end; j++) {
            if (list.get(j) <= origin) {
                i++;

                int swapTemp = list.get(i);
                list.set(i,list.get(j));
                list.set(j,swapTemp);
            }
        }

        int swapTemp = list.get(i+1);
        list.set(i+1,list.get(end));
        list.set(end,swapTemp);

        return i+1;
    }
}
