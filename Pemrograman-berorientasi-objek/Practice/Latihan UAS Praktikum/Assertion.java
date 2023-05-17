public class Assertion {

}

class TimeOfDay {
    protected int h, m, s;

    public TimeOfDay(int seconds) throws IllegalArgumentException {
        if (seconds < 0 || seconds > 86399) {
            throw new IllegalArgumentException();
        }
        // assert seconds >= 0 && seconds <= 86399: new IllegalArgumentException();
    }
}
