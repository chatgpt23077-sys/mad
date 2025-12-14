import java.util.LinkedList;
import java.util.Scanner;

public class LinkedListDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();

        System.out.println("Linked List=" + list + ", size=" + list.size());

        list.add(10);
        list.add(20);
        list.add(45.6);
        list.add(5.7);
        list.add("abc");
        list.add("xyz");

        System.out.println("Linked List after insertion=" + list + ", size=" + list.size());

        list.addFirst("first item");
        list.addLast("last item");
        list.add(3, 50);

        System.out.println("Linked List after inserting at first, last and 3rd index=");
        System.out.println(list + ", size=" + list.size());

        System.out.println("Enter a positive index to fetch an item:");
        int i = sc.nextInt();
        System.out.println("Element at " + i + "=" + list.get(i));

        System.out.println("Enter a positive index to remove item:");
        i = sc.nextInt();
        list.remove(i);

        System.out.println("Linked List after removing " + i + "=" + list);

        list.set(4, 100);
        System.out.println("Linked List after updating value at 4=" + list);

        list.clear();
        System.out.println("Now list=" + list + ", size=" + list.size());
    }
}
