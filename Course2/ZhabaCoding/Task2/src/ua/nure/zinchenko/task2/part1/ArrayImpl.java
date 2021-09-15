package ua.nure.zinchenko.task2.part1;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ArrayImpl<E> implements Array<E> {
	private Object[] array;
	private int count;
	
	public ArrayImpl() {
		array = new Object[10];
		count = 0;
	}	

	@Override
	public void clear() {
		count = 0;
		array = new Object[10];		
	}

	@Override
	public int size() {
		return count;
	}

	@Override
	public Iterator<E> iterator() {
		return new IteratorImpl<>(this);
	}

	@Override
	public void add(E element) {
		if(count >= array.length) {
			Object[] buffer =  new Object[array.length + (array.length>>1)];
			for(int i = 0; i < array.length; i++) {
				buffer[i] = array[i];
			}
			array = buffer;
		}
		array[count] = element;
		count++;
	}

	@Override
	public void set(int id, E element) {
		if(id >= count || id < 0) {
			throw new IndexOutOfBoundsException();
		}
		array[id] = element;
	}

	@SuppressWarnings("unchecked")
	@Override
	public E get(int id) {
		if(id >= count || id < 0) {
			throw new IndexOutOfBoundsException();
		}
		return (E)array[id];
	}

	@Override
	public int indexOf(E element) {
		if(count > 0) {
			for(int i = 0; i < count; i++) {
				if(array[i].equals(element)) {
					return i;
				}
			}
		}
		return -1;
	}

	@Override
	public void remove(int id) {
		if(id >= count || id < 0) {
			throw new IllegalStateException();
		}
		if(id < count-1) {
			for(; id < count-1; id++) {
				array[id] = array[id+1];
			}
		}
		array[count-1] = null;
		count--;
	}
	
	public class IteratorImpl<T> implements Iterator<T>{
		ArrayImpl<T> impl;
		int position;
		
		public IteratorImpl(ArrayImpl<T> impl) {
			this.impl = impl;
			position = 0;
		}

		@Override
		public boolean hasNext() {
			return position < impl.size();
		}

		@Override
		public T next() {
			if(hasNext()){
				T buffer = impl.get(position);
				position++;
				return buffer;
			}else {
				throw new NoSuchElementException();
			}
		}
		
		@Override
		public void remove() {
			impl.remove(--position);
		}
		
	}

	@Override
	public String toString() {
		if(count != 0) {
			StringBuilder result = new StringBuilder("[");
			
			for(int i = 0; i < count; i++) {
				result.append(array[i]).append(", ");
			}
			result.replace(result.length()-2, result.length(), "]");	
			return result.toString();
		}
		return "[]";
	}
}
