package ua.nure.zinchenko.task2.part3;

public class Part3 {
	public static void main(String[] args) {
		QueueImpl<String> queue = new QueueImpl<>();
		queue.enqueue("A");
		queue.enqueue("B");
		queue.enqueue("C");
		queue.enqueue("D");

		System.out.println(queue.toString());
		queue.dequeue();
		System.out.println(queue.toString());
		System.out.println(queue.top());
	}
}
