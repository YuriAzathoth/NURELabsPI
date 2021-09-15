package ua.nure.zinchenko.task1;

public class Part7 {
	public static void main(String[] args) {
		int num = 0;
		num = Integer.parseInt(args[0]);
		int[] primes = Part5.getPrimeNumbers(num);
		System.out.println(maxSum(primes));
	}
	
	private static String maxSum(int[] primes) {
		int i = 1;
		int max = 0;
		for(int num : primes) {
			int sum = digitsSum(num);
			if(max == sum) {
				i++;
			}
			if(max < sum) {
				max = sum;
				i = 1;
			}
		}
		return max + " " + i;
	}
	
	private static int digitsSum(int num) {
		int sum = 0;
		while(num > 1) {
			sum += num % 10;
			num /= 10;
		}
		if(num == 1) {
			sum++;
		}
		return sum;
	}
}
