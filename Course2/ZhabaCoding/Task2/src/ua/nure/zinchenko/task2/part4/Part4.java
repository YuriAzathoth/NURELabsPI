package ua.nure.zinchenko.task2.part4;

public class Part4 {
	public static void main(String[] args) {
		StackImpl<String> stack = new StackImpl<>();
		stack.push("A");
		stack.push("B");
		stack.push("C");

		System.out.println(stack.toString());
		for(String elem:stack) {
			System.out.println(elem);
		}
		System.out.println(new StringBuilder(stack.pop()).append(" size: ").append(stack.size()));
		System.out.println(new StringBuilder(stack.top()).append(" size: ").append(stack.size()));
	}
}
