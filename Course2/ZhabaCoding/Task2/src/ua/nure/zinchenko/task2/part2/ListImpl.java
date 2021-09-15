package ua.nure.zinchenko.task2.part2;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ListImpl<E> implements List<E> {
	public static class Node<E> {
		public E object;
		public Node<E> next;
		public Node<E> prev;

		public Node(E object, Node<E> next, Node<E> prev) {
			this.object = object;
			this.next = next;
			this.prev = prev;
		}
	}

	private Node<E> first;
	private Node<E> last;
	private int size;

	public class IteratorImpl<T> implements Iterator<T> {
		ListImpl<T> list;
		Node<T> node;
		T object;

		public IteratorImpl(Node<T> node,ListImpl<T> list) {
			this.node = node;
			this.list = list;
		}

		@Override
		public boolean hasNext() {
			return node != null;
		}

		@Override
		public T next() {
			if(hasNext()){
				object = node.object;
				node = node.next;
				return object;
			} else {
				throw new NoSuchElementException();
			}
		}

		@Override
		public void remove() {
			list.remove(object);
			object = null;
		}
	}

	public ListImpl() {
		// Empty constructor
	}

	@Override
	public String toString() {
		if(size != 0) {
			StringBuilder result = new StringBuilder("[");

			Node<E> buffer = first;
			while(buffer != null) {
				result.append(buffer.object).append(", ");
				buffer = buffer.next;
			}
			result.replace(result.length()-2, result.length(), "]");
			return result.toString();
		}
		return "[]";
	}

	@Override
	public void clear() {
		size = 0;
		first = null;
		last = null;
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public Iterator<E> iterator() {
		return new IteratorImpl<>(first,this);
	}

	@Override
	public void addFirst(E node) {
		if(size == 0) {
			first = new Node<>(node,null,null);
			last = first;
		} else {
			first.prev = new Node<>(node,first,null);
			first = first.prev;
		}
		size++;
	}

	@Override
	public void addLast(E node) {
		if(size == 0) {
			first = new Node<>(node,null,null);
			last = first;
		} else {
			last.next = new Node<>(node,null,last);
			last = last.next;
		}
		size++;
	}

	@Override
	public void removeFirst() {
		if(size != 0) {
			if(size == 1){
				clear();
			} else {
				first = first.next;
				first.prev = null;
				size--;
			}
		}
	}

	@Override
	public void removeLast() {
		if(size != 0) {
			if(size == 1) {
				clear();
			} else {
				last = last.prev;
				last.next = null;
				size--;
			}
		}
	}

	@Override
	public E getFirst() {
		E buffer = first.object;
		removeFirst();
		return buffer;
	}

	public E peek(int index) {
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException();
		}
		Node<E> buffer = first;
		for(int i = 0; i < index; i++) {
			buffer = buffer.next;
		}
		return buffer.object;
	}

	@Override
	public E getLast() {
		E buffer = last.object;
		removeLast();
		return buffer;
	}

	@Override
	public E search(E node) {
		Node<E> buffer = first;
		while(buffer != null) {
			if(buffer.object.equals(node)) {
				return buffer.object;
			}
			buffer = buffer.next;
		}
		return null;
	}

	@Override
	public boolean remove(E node) {
		if(size == 0 || node == null) {
			throw new IllegalStateException();
		}
		Node<E> buffer = first;
		while(buffer != null) {
			if(buffer.object.equals(node)) {
				if(buffer.equals(first)) {
					removeFirst();
					return true;
				}
				if(buffer.equals(last)) {
					removeLast();
					return true;
				}
				buffer.prev.next = buffer.next;
				buffer.next.prev = buffer.prev;
				return true;
			}
			buffer = buffer.next;
		}
		return false;
	}
}
