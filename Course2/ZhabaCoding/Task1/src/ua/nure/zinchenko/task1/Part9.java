package ua.nure.zinchenko.task1;

public class Part9 {
	public static void main(String[] args) {
		int n = 0;
		n = Integer.parseInt(args[0]);
		System.out.println(getPrimeNumbers(n));
	}
	
	private static String getPrimeNumbers(int num) {
		if(num < 1) {
			return "";
		}
		StringBuilder result = new StringBuilder();
		for(int counter = 2; counter <= num;counter++) {
			if(Part5.isPrime(counter)) {
				result.append(counter + " ");
			}
		}
		return result.deleteCharAt(result.length() - 1).toString();
	}
}
