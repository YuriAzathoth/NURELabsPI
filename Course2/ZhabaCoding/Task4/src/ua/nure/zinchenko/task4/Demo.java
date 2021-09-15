package ua.nure.zinchenko.task4;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Demo {
    private static final InputStream STD_IN = System.in;
    private static final String ENCODING = "Cp1251";

    public static void main(String[] args) throws IOException {
        System.setIn(new ByteArrayInputStream(
                "asdf^Latn^Cyrl^stop^"
                        .replace("^", System.lineSeparator()).getBytes(ENCODING)));

        System.out.println("=================== PART1");
        Part1.main(args);

        System.out.println("=================== PART2");
        Part2.main(args);

        System.setIn(new ByteArrayInputStream(
                "table ru^table en^key locale name^apple ru^stop^"
                        .replace("^", System.lineSeparator()).getBytes(ENCODING)));

        System.out.println("=================== PART3");
        Part3.main(args);

        System.setIn(STD_IN);

        System.out.println("=================== PART4");
        Part4.main(args);

        System.out.println("=================== PART5");
        Part5.main(args);
    }
}
