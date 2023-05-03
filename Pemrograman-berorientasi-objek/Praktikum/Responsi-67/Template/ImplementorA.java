public class ImplementorA extends Processor {
    @Override
    public boolean process1() {
        return true;
    }

    @Override
    public boolean process2() {
        return false;
    }

    @Override
    public void process3() {
        System.out.println("Implementor A running process 1.");
    }

    @Override
    public void process4() {
        System.out.println("Implementor A running process 2.");
    }

    @Override
    public void process5() {
        System.out.println("Implementor A running process 3.");
    }
}
