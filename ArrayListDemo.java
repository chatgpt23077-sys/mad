import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList list = new ArrayList();

        list.add(10);
        list.add(20);
        list.add(45.6);
        list.add(5.7);
        list.add("abc");

        System.out.println("ArrayList = " + list);

        System.out.println("Enter index to fetch:");
        int i = sc.nextInt();
        System.out.println("Element = " + list.get(i));

        list.remove(2);
        System.out.println("After removal = " + list);

        list.clear();
        System.out.println("List cleared = " + list);
    }
}
