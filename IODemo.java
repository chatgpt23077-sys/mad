import java.io.*;

public class IODemo {
    public static void main(String[] args) throws Exception {
        FileOutputStream fout = new FileOutputStream("demo.txt");
        String msg = "Java IO Streams";
        fout.write(msg.getBytes());
        fout.close();

        FileInputStream fin = new FileInputStream("demo.txt");
        int i;
        while ((i = fin.read()) != -1)
            System.out.print((char) i);
        fin.close();
    }
}
