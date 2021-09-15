package ua.nure.zinchenko.task4;

public class Part5 {
    public static void main(String[] args){
        Tree<Integer> intTree = new Tree<>();
        System.out.println(intTree.add(8));
        Integer[] data = new Integer[]{3, 10, 1, 6, 14, 4, 7, 13};
        intTree.add(data);
        intTree.print();
        System.out.println(intTree.remove(100));
        System.out.println(intTree.remove(5));
        intTree.print();
    }
}
