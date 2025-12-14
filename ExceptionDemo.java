import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int arr[] = {10, 20, 30, 40, 50};

        try {
            System.out.println("Enter the index of array (1 to quit): ");
            int index = sc.nextInt();

            System.out.println("Enter two integers:");
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println("Value at index=" + arr[index]);
            System.out.println("Division Result=" + (a / b));
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index value is out of bounds");
        }
        catch (InputMismatchException e) {
            System.out.println("Entered value is not valid, decimal values are not allowed");
        }
        catch (ArithmeticException e) {
            System.out.println("Denominator should not be zero");
        }
    }
}
