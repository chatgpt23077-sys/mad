import java.util.Scanner;
import java.util.StringTokenizer;

public class StrTokenDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the integer string (space as delimiter): ");
        String intString = sc.nextLine();

        StringTokenizer st = new StringTokenizer(intString, " ");
        int sum = 0;

        System.out.println("Number of integer tokens=" + st.countTokens());

        while (st.hasMoreTokens()) {
            int val = Integer.parseInt(st.nextToken());
            sum = sum + val;
            System.out.println(val);
        }

        System.out.println("Sum = " + sum);
    }
}
