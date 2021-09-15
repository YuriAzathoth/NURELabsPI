package ua.nure.zinchenko.task3;

public class Part5 {
    private static final int[] ROMNUMS = new int[]{100, 90, 50, 40, 10, 9, 5, 4};
    private static final int FIVE = 5;
    private static final int FOR = 4;
    private static final int COUNT = 100;

    public static void main(String[] args){
        for(int i = 1; i <= COUNT; i++){
            String dec = decimal2Roman(i);
            System.out.println(i + " --> " + dec + " --> " + roman2Decimal(dec));
        }
    }

    public static String decimal2Roman(int num) {
        StringBuilder result = new StringBuilder();
        while (num >= 1){
            if(num == ROMNUMS[0]){
                return "C";
            }
            if (num >= ROMNUMS[1]) {
                result.append("XC");
                num -= ROMNUMS[1];
            }else if (num >= ROMNUMS[2]) {
                result.append("L");
                num -= ROMNUMS[2];
            } else if (num >= ROMNUMS[3]) {
                result.append("XL");
                num -= ROMNUMS[3];
            } else if (num >= ROMNUMS[4]) {
                result.append("X");
                num -= ROMNUMS[4];
            } else if (num >= ROMNUMS[5]) {
                result.append("IX");
                num -= ROMNUMS[5];
            } else if (num >= FIVE) {
                result.append("V");
                num -= FIVE;
            } else if (num >= FOR) {
                result.append("IV");
                num -= FOR;
            } else {
                result.append("I");
                --num;
            }
        }
        return result.toString();
    }

    public static int roman2Decimal(String data) {

        return recRom2Dec(data);
    }

    private static int recRom2Dec(String data){
        int result = 0;
        if (data.startsWith("C")){
            result =  ROMNUMS[0] + recRom2Dec(data.substring(1));
        }else if (data.startsWith("XC")){
            result = ROMNUMS[1] + recRom2Dec(data.substring(2));
        }else if (data.startsWith("L")){
            result = ROMNUMS[2] + recRom2Dec(data.substring(1));
        }else if (data.startsWith("XL")){
            result = ROMNUMS[3] + recRom2Dec(data.substring(2));
        }else if (data.startsWith("X")){
            result = ROMNUMS[4] + recRom2Dec(data.substring(1));
        }else if (data.startsWith("IX")){
            result = ROMNUMS[5] + recRom2Dec(data.substring(2));
        }else if (data.startsWith("V")){
            result = FIVE + recRom2Dec(data.substring(1));
        }else if (data.startsWith("IV")){
            result = FOR + recRom2Dec(data.substring(2));
        }else if (data.startsWith("I")){
            result = 1 + recRom2Dec(data.substring(1));
        }
        return result;
    }
}
