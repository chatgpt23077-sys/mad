import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MouseEventDemo extends Applet implements MouseListener {
    String msg = "";

    public void init() {
        addMouseListener(this);
    }

    public void mouseClicked(MouseEvent me) {
        msg = "Mouse Clicked";
        repaint();
    }

    public void mouseEntered(MouseEvent me) {
        msg = "Mouse Entered";
        repaint();
    }

    public void mouseExited(MouseEvent me) {
        msg = "Mouse Exited";
        repaint();
    }

    public void mousePressed(MouseEvent me) {
        msg = "Mouse Pressed";
        repaint();
    }

    public void mouseReleased(MouseEvent me) {
        msg = "Mouse Released";
        repaint();
    }

    public void paint(Graphics g) {
        g.drawString(msg, 50, 50);
    }
}

