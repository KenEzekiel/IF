public class ImplementorC extends Processor {
    @Override
    public boolean process1() {
        return false;
    }

    @Override
    public boolean process2() {
        return false;
    }

    @Override
    public void process3() {
        System.out.println("Implementor C running process 3.");
    }

    @Override
    public void process4() {
        System.out.println("Implementor C running process 4.");
    }

    @Override
    public void process5() {
        System.out.println("Implementor C running process 5.");
    }
}
