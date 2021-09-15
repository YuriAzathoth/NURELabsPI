package ua.nure.zinchenko.task1;

public class Part6 {
	private static final int EXTRAINL = 3;

	public static void main(String[] args) {
		int num = 0;
		num = Integer.parseInt(args[0]);
		System.out.println(getFactorization(num));
	}
	
	public static int nextPrime(int x) {
		if(x < 2) {
			return 2;
		}
		int result = x+1;
		while(true) {
			if(Part5.isPrime(result)) {
				return result;
			} else {
				result++;
			}
		}
	}
	
	private static String getFactorization(int num) {
		StringBuilder res = new StringBuilder(num + " = ");
		int devNumber = 2;
		int number = 0;
		while(num > 1) {
			if(num % devNumber == 0) {
				number++;
				num /= devNumber;
			} else {
				if(number != 0) {
					res.append(devNumber + "^" + number + " x ");
					number = 0;
				}
				devNumber++;
			}
			if(num == 1 && number > 0) {
				if(devNumber > 2) {
					res.delete(res.length() - EXTRAINL, res.length()).append(" x " + devNumber + "^"+ number);
				} else {
					res.append(devNumber + "^"+ number);
				}
			}				
		}
		return res.toString();
	}
}
