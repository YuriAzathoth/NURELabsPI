package ua.nure.zinchenko.task2.part1;

import java.util.Iterator;

public class Part1 {

	public static void main(String[] args) {
		ArrayImpl<String> array = new ArrayImpl<>();
		array.add("A");
		array.add("B");
		array.add("C");

		Iterator<String> it = array.iterator();
		while(it.hasNext()) {
			String elem = it.next();
			System.out.println(new StringBuilder(elem).append(" size: ").append(array.size()));
		}
		array.set(1, "D");

		System.out.println(array.get(1));
		System.out.println(array.indexOf("C"));
		array.remove(0);
		System.out.println(array.toString());
		array.clear();
		System.out.println(array.toString());
	}

}
