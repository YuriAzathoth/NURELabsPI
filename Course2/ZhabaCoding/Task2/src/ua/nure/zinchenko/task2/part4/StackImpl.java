package ua.nure.zinchenko.task2.part4;

import java.util.Iterator;
import ua.nure.zinchenko.task2.part2.ListImpl;

public class StackImpl<E> implements Stack<E> {
	private final ListImpl<E> stack;

	public StackImpl() {
		stack = new ListImpl<>();
	}

	@Override
	public void clear() {
		stack.clear();
	}

	@Override
	public int size() {
		return stack.size();
	}

	@Override
	public Iterator<E> iterator() {
		return stack.iterator();
	}

	@Override
	public void push(E element) {
		stack.addFirst(element);
	}

	@Override
	public E pop() {
		return stack.getFirst();
	}

	@Override
	public E top() {
		return stack.peek(0);
	}

	@Override
	public String toString() {
		if(stack.size() != 0) {
			StringBuilder result = new StringBuilder("]");
			for(E element:stack) {
				result.insert(0, element).insert(0, ", ");
			}
			result.replace(0, 2, "[");
			return result.toString();
		}
		return "[]";
	}
}
