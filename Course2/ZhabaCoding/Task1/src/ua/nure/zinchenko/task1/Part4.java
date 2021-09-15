package ua.nure.zinchenko.task1;

public class Part4 {
	private static final int ASCIIBEGIN = 48;
	private static final int ASCIIEND = 58;

	public static void main(String[] args) {
		int sum = 0;
		for(String arg : args) {
			sum += sumOfNumsInString(arg);
		}
		System.out.println(sum);

	}
	
	private static int sumOfNumsInString(String arg) {
		int sum = 0;
		for(int i = 0; i < arg.length();i++) {
			if((int)arg.charAt(i) < ASCIIEND && (int)arg.charAt(i) > ASCIIBEGIN) {
				sum += (int)arg.charAt(i) - ASCIIBEGIN;
			}
		}
		return sum;
	}
}
