package ua.nure.zinchenko.task2;

import java.util.Iterator;

public interface Container<E> extends Iterable<E> {
	void clear();
	int size();
	String toString();
	Iterator<E> iterator();
}
