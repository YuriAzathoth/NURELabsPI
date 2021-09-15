package ua.nure.zinchenko.task4;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;

public class Part2 {
    private static final InputStream STD_IN = System.in;
    private static final String CODEPAGE = "Cp1251";

    public static void main(String[] args){
        try {
            InputStream stream = new ByteArrayInputStream("asd 43 asdf asd 43^434 asdf^kasdf asdf stop asdf"
                    .replace("^", System.lineSeparator()).getBytes(CODEPAGE));
            System.setIn(stream);
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        WordContainer.main(args);
        System.setIn(STD_IN);
    }
}
