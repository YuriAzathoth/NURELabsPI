package ua.nure.zinchenko.task1;

public class Part8 {
	public static void main(String[] args) {
		int n = 0;
		n = Integer.parseInt(args[0]);
		System.out.println(pascalTriangle(pascal(n)));
	}

	public static int[][] pascal(int num) {
		if(num < 1) {
			return new int[0][0];
		}
		int[][] result = new int[num][];
		for(int i = 0; i < num; i++) {
			result[i] = new int[i+1];
			for(int j = 0; j < result[i].length; j++) {
				result[i][j] = c(i,j);
			}
		}
		return result;
	}
	
	private static String pascalTriangle(int[][] pascal) {
		StringBuilder result = new StringBuilder();
		for(int[] num : pascal) {
			StringBuilder row = new StringBuilder();
			for(int i = 0; i < num.length; i++) {
				row.append(num[i] + " ");
			}
			for(int i = 0; i < pascal.length - num.length;i++) {
				row.insert(0, " ");
			}
			result.append(row.substring(0,row.length()-1) + "\n");
		}
		return result.toString();
	}
	
	private static int c(int n,int k) {
		return fact(n) / (fact(k) * fact(n - k));
	}

	private static int fact(int num) {
		int value = 1;
		for (int i = 2; i <= num; i++) {
			value *= i;
		}
		return value;
	}
}
