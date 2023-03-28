class Point {
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
        Point p1 = new Point(1, 2);
        Point p2 = new Point(3, 4);
        Point p3 = new Point();
        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);

        Point[] points = new Point[10];
        for (int i = 0; i < 10; i++) {
            points[i] = new Point();
        }
        System.out.println("Points array with " + points.length + " points created");
        for (Point point : points) {
            System.out.println(point);
        }
    }

}
