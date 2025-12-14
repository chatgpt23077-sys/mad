import java.util.*;

public class IteratorDemo {
    public static void main(String[] args) {
        ArrayList list = new ArrayList();

        for (int i = 10; i < 15; i++)
            list.add(i);

        System.out.println("ArrayList = " + list);

        Iterator it = list.iterator();
        System.out.println("Using Iterator:");
        while (it.hasNext())
            System.out.print(it.next() + " ");

        System.out.println("\nUsing ListIterator (Forward):");
        ListIterator lit = list.listIterator();
        while (lit.hasNext())
            System.out.print(lit.next() + " ");

        System.out.println("\nUsing ListIterator (Backward):");
        while (lit.hasPrevious())
            System.out.print(lit.previous() + " ");
    }
}
