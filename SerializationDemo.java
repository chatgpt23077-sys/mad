import java.io.*;

class Student implements Serializable {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

public class SerializationDemo {
    public static void main(String[] args) {
        try {
            Student s = new Student(101, "Dennis");

            FileOutputStream fout = new FileOutputStream("student.txt");
            ObjectOutputStream out = new ObjectOutputStream(fout);
            out.writeObject(s);
            out.close();

            System.out.println("Object Serialized Successfully");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
