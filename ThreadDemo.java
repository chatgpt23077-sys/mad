class One extends Thread {
    public void run() {
        int sum = 0;
        System.out.println("Executed thread = " + Thread.currentThread().getName());
        for (int i = 10; i < 15; i++) {
            sum = sum + i;
            System.out.print(i + " ");
        }
        System.out.println("\nSum = " + sum);
    }
}

class Two implements Runnable {
    public void run() {
        int sum = 0;
        System.out.println("Executed thread = " + Thread.currentThread().getName());
        for (int i = 20; i < 25; i++) {
            sum = sum + i;
            System.out.print(i + " ");
        }
        System.out.println("\nSum = " + sum);
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        One t1 = new One();
        Two obj = new Two();
        Thread t2 = new Thread(obj);

        t1.start();
        t2.start();
    }
}
