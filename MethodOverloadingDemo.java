class Sum {
    int sum(int x, int y) {
        System.out.println("Sum of 2 integer arguments invoked");
        return (x + y);
    }

    int sum(int x, int y, int z) {
        System.out.println("Sum of 3 integer arguments invoked");
        return (x + y + z);
    }

    double sum(double x, double y) {
        System.out.println("Sum of 2 double arguments invoked");
        return (x + y);
    }
}

public class MethodOverloadingDemo {
    public static void main(String[] args) {
        Sum s = new Sum();
        System.out.println(s.sum(10, 20));
        System.out.println(s.sum(10, 20, 30));
        System.out.println(s.sum(10.5, 20.5));
    }
}
