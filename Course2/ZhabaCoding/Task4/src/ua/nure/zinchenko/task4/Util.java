package ua.nure.zinchenko.task4;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

final class Util {
    private static final String CODEPAGE = "Cp1251";

    private Util(){
        throw new IllegalStateException("Utility class");
    }

    public static String readFile(String path) {
        String result = null;
        try {
            result = new String(Files.readAllBytes(Paths.get(path)), CODEPAGE);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result;
    }
}
