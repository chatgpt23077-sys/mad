class MyException extends Exception {
    MyException(String msg) {
        super(msg);
    }
}

public class UserDefinedExceptionDemo {
    public static void main(String[] args) {
        int age = 15;

        try {
            if (age < 18) {
                throw new MyException("Age is not valid for voting");
            }
            System.out.println("Eligible for voting");
        }
        catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }
}
