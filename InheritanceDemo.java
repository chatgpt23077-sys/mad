class One {
    String one_str = "Class One";

    void displayOne() {
        System.out.println("Parent: " + one_str);
    }
}

class Two extends One {
    String two_str = "Class Two";

    void displayTwo() {
        displayOne();
        System.out.println("Single level inheritance from " + one_str);
    }
}

class Three extends Two {
    String three_str = "Class Three";

    void displayThree() {
        displayTwo();
        System.out.println("Multi level inheritance from " + two_str);
    }
}

public class InheritanceDemo {
    public static void main(String[] args) {
        Three obj = new Three();
        obj.displayThree();
    }
}
