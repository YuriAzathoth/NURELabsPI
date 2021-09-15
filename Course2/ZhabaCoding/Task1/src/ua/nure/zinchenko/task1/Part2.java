package ua.nure.zinchenko.task1;

public class Part2 {
	public static void main(String[] args) {
		StringBuilder res = new StringBuilder();
		if(args.length > 0) {
			for(String arg : args) {
				res.insert(0, " " + arg);
			}
		}
		System.out.println(res.substring(1));
	}
}
