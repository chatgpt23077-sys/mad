class MySource {
    synchronized void display(String msg) {
        System.out.println("Synchronized method:");
        for (int i = 0; i < msg.length(); i++) {
            System.out.print(msg.charAt(i));
            try {
                Thread.sleep(200);
            } catch (Exception e) {}
        }
        System.out.println();
    }
}

class MyThread extends Thread {
    MySource ms;
    String msg;

    MyThread(MySource ms, String msg) {
        this.ms = ms;
        this.msg = msg;
        start();
    }

    public void run() {
        ms.display(msg);
    }
}

public class SyncDemo {
    public static void main(String[] args) {
        MySource obj = new MySource();
        new MyThread(obj, "First");
        new MyThread(obj, "Second");
    }
}
