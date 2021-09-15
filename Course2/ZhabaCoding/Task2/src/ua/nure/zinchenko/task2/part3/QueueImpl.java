package ua.nure.zinchenko.task2.part3;

import java.util.Iterator;
import ua.nure.zinchenko.task2.part2.ListImpl;

public class QueueImpl<E> implements Queue<E> {
	private final ListImpl<E> queue;

	public QueueImpl() {
		queue = new ListImpl<>();
	}

	@Override
	public void clear() {
		queue.clear();
	}

	@Override
	public int size() {
		return queue.size();
	}

	@Override
	public Iterator<E> iterator() {
		return queue.iterator();
	}

	@Override
	public void enqueue(E element) {
		queue.addLast(element);
	}

	@Override
	public E dequeue() {
		return queue.getFirst();
	}

	@Override
	public E top() {
		return queue.peek(0);
	}

	@Override
	public String toString() {
		return queue.toString();
	}
}
