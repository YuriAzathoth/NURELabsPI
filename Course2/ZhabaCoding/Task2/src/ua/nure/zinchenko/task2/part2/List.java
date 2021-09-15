package ua.nure.zinchenko.task2.part2;
import ua.nure.zinchenko.task2.Container;

public interface List<E> extends Container<E> {
	void addFirst(E element);
	void addLast(E element);

	void removeFirst();
	void removeLast();

	E getFirst();
	E getLast();

	E search(E element);

	// Removes the first occurrence of the specified element.
	// Returns true if this list contained the specified element.
	// (use 'equals' method to check an occurrence)
	boolean remove(E element);
}
