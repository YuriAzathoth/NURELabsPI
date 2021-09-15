package ua.nure.zinchenko.task1;

public class Part5 {
	public static void main(String[] args) {
		int num = 0;
		num = Integer.parseInt(args[0]);
		int[] primes = getPrimeNumbers(num);
		StringBuilder result = new StringBuilder();
		for(int el : primes) {
			result.append(el + " ");
		}
		if(result.length() != 0) {
			result.deleteCharAt(result.length()-1);
		}
		System.out.println(result);
	}
	
	public static boolean isPrime(int num) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				return false;
            }
        }
		return true;
	}
	
	public static int[] getPrimeNumbers(int num) {
		if(num < 1) {
			return new int[0];
		}
		
		int[] array = new int[num];
		int counter = 2;
		int i = 0;
		while(i < num) {
			if(isPrime(counter)) {
				array[i] = counter;
				i++;
			}
			counter++;
		}
		return array;
	}
}
