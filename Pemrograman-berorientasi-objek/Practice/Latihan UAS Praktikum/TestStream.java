import java.lang.reflect.*;
import java.util.Arrays;
import java.util.List;

// Java Basic (Constructor, Overriding, Overloading, Method, Field, Inheritance, Interface)
// Reflection
// Exception
// Wildcard
// Generic
// Java Collection API
// Design Pattern
// SOLID

public class TestStream {

    public static void main(String[] args) {

        List<String> myList = Arrays.asList("a1", "b1", "c2", "c1");
        myList.stream()
                .filter(s -> s.startsWith("c"))
                .map(String::toUpperCase)
                .sorted()
                .forEach(System.out::println);
        System.out.println(myList);
        // Runnable r = new Runnable() {
        // @Override
        // public void run() {
        // while (true) {
        // System.out.println("Jamaica");
        // try {
        // Thread.sleep(1000);
        // } catch (Exception e) {
        // }
        // }
        // }
        // };
        // new Thread(r).start();

        // Runnable alt = () -> {
        // while (true) {
        // System.out.println("Fiji");
        // try {
        // Thread.sleep(1000);
        // } catch (Exception e) {
        // }
        // }
        // };

        // new Thread(alt).start();
        Class<?> c = String.class;
        Method m[] = c.getMethods();
        for (Method e : m) {
            System.out.println(e.getName());
        }
    }
}
