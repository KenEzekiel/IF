import java.util.List;

public class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan(List<Integer> list, int n) {
        this.list = list;
        this.n = n;
    }

    public void reset() {
        this.list.clear();
        for (int i = 0; i < n; i++) {
            this.list.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long start = Util.getTime();
        Integer ret = this.list.get(idx);
        long end = Util.getTime();

        return end - start;
    }

    public long del(int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i = 0; i < t; i++) {
            this.list.remove(idx);
        }
        long end = Util.getTime();

        return end - start;
    }
}
