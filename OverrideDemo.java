class Parent {
    void show() {
        System.out.println("Parent class method");
    }
}

class Child extends Parent {
    void show() {
        System.out.println("Child class overridden method");
    }
}

public class OverrideDemo {
    public static void main(String[] args) {
        Parent p = new Child();
        p.show();
    }
}
