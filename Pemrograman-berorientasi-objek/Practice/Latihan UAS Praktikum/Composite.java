import java.util.*;

public class Composite {
    public static void main(String[] args) {
        Window w = new Window();
        Picture p = new Picture("hewan");
        Text t = new Text("ini adalah hewan");

        w.add(p);
        w.add(t);

        w.draw();

    }
}

abstract class Component {
    abstract void draw();
}

final class Picture extends Component {
    private String image;

    public Picture(String image) {
        this.image = image;
    }

    @Override
    public void draw() {
        System.out.println("Menggambar " + this.image);
    }
}

final class Text extends Component {
    private String text;

    public Text(String text) {
        this.text = text;
    }

    @Override
    public void draw() {
        System.out.println("Menulis " + this.text);
    }

}

// Container abstract
abstract class Container extends Component {
    private List<Component> components = new ArrayList<>();

    public void add(Component component) {
        components.add(component);
    }

    public void remove(Component component) {
        components.remove(component);
    }

    public Component getChild(int index) {
        return components.get(index);
    }

    public void draw() {
        for (Component component : components) {
            component.draw();
        }
    }
}

// Container konkret
final class Window extends Container {
    public void draw() {
        System.out.println("Menggambar window");
        super.draw();
    }
}

// Container konkret
final class Panel extends Container {
    public void draw() {
        System.out.println("Menggambar panel");
        super.draw();
    }
}
