package ua.nure.zinchenko.task4;

public class Tree<E extends Comparable<E>> {
    private Node<E> root;
    private int count;

    public Tree() {
        count = 0;
        root = null;
    }

    public boolean add(E element) {
        if(contains(element)) {
            return false;
        }
        root = insertRec(root, element);
        return true;
    }

    private Node<E> insertRec(Node<E> current, E obj) {
        if (current == null) {
            current = new Node<>(obj);
            return current;
        }

        if (obj.compareTo(current.obj) < 0){
            current.lhs = insertRec(current.lhs, obj);
        } else if (obj.compareTo(current.obj) > 0){
            current.rhs = insertRec(current.rhs, obj);
        }
        return current;
    }

    private boolean contains(E element){
        return containsRec(root,element);
    }

    private boolean containsRec(Node<E> current, E value) {
        if (current == null) {
            return false;
        }
        if (value == current.obj) {
            return true;
        }
        return value.compareTo(current.obj) < 0 ? containsRec(current.lhs, value) : containsRec(current.rhs, value);
    }

    public void add(E[] elements) {
        for(E el : elements){
            add(el);
        }
    }

    public boolean remove(E element) {
        if(!contains(element)){
            return false;
        }

        root = this.removeRec(root, element);
        count--;
        return true;
    }

    private Node<E> removeRec(Node<E> root, E obj) {
        if (root == null){
            return root;
        }

        if (obj.compareTo(root.obj) < 0){
            root.lhs = removeRec(root.lhs, obj);
        } else if (obj.compareTo(root.obj) > 0){
            root.rhs = removeRec(root.rhs, obj);
        } else {
            if (root.lhs == null){
                return root.rhs;
            } else if (root.rhs == null){
                return root.lhs;
            }

            root.obj = minValue(root.rhs);
            root.rhs = removeRec(root.rhs, root.obj);
        }

        return root;
    }

    private E minValue(Node<E> root) {
        E minv = root.obj;
        while (root.lhs != null) {
            minv = root.lhs.obj;
            root = root.lhs;
        }
        return minv;
    }

    void print() {
        printRec(root,0);
    }

    private void printRec(Node<E> cur, int level) {
        if(cur != null){
            printRec(cur.lhs, level + 2);
            for(int i = 0; i < level; i++){
                System.out.print(" ");
            }
            System.out.println(cur.obj);
            printRec(cur.rhs, level + 2);
        }
    }

    public int getCount(){
        return count;
    }

    private static class Node<E> {
        public E obj;
        public Node<E> lhs;
        public Node<E> rhs;

        Node(E obj) {
            this.obj = obj;
            lhs = null;
            rhs = null;
        }
    }
}
