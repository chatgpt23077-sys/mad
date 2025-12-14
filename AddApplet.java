import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class AddApplet extends Applet implements ActionListener {
    TextField t1, t2, t3;
    Button b;

    public void init() {
        t1 = new TextField(5);
        t2 = new TextField(5);
        t3 = new TextField(5);
        t3.setEditable(false);

        b = new Button("Add");
        b.addActionListener(this);

        add(t1);
        add(t2);
        add(b);
        add(t3);
    }

    public void actionPerformed(ActionEvent ae) {
        int a = Integer.parseInt(t1.getText());
        int b = Integer.parseInt(t2.getText());
        t3.setText(String.valueOf(a + b));
    }
}
