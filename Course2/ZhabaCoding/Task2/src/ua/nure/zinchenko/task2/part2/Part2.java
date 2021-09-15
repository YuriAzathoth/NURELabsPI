package ua.nure.zinchenko.task2.part2;

import java.util.Iterator;

public class Part2 {
	public static void main(String[] args) {
		ListImpl<String> list = new ListImpl<>();
		list.addLast("B");
		list.addLast("C");
		list.addLast("D");
		list.addLast("E");
		list.addLast("F");
		list.addFirst("A");

		System.out.println(new StringBuilder(list.toString()).append(" size: ").append(list.size()));

		Iterator<String> it = list.iterator();
		while(it.hasNext()) {
			String elem = it.next();
			System.out.println(elem);
		}

		list.removeFirst();
		list.removeLast();

		System.out.println(list.getFirst());
		System.out.println(list.getLast());
		System.out.println(list.search("D"));
		list.clear();
		System.out.println(list.toString());
	}
}
