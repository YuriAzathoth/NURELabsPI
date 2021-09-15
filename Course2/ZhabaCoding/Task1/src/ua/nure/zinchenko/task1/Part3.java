package ua.nure.zinchenko.task1;

public class Part3 {
	public static void main(String[] args) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		System.out.println(nod(a,b) + " " + nok(a,b));
	}
	
	private static int nod(int a, int b) {
		return b == 0 ? a : nod(b,a % b);
	}
	
	private static int nok(int a,int b) {
		return a / nod(a,b) * b;
	}
}
