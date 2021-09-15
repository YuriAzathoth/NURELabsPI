package ua.nure.zinchenko.task2.part1;

import ua.nure.zinchenko.task2.Container;

public interface Array<E> extends Container<E> {
	void add(E element);
	void set(int index, E element);
	E get(int index);
	int indexOf(E element);
	void remove(int index);
}
