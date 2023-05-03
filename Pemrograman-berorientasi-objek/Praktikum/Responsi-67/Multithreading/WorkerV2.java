import java.util.ArrayList;
import java.util.List;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2() {
        this.tasks = new ArrayList<Task>();
    }

    public void addTask(Task newTask) {
        this.tasks.add(newTask);
    }

    @Override
    public void run() {
        for (Task task : tasks) {
            new Thread(() -> {
                try {
                    Thread.sleep(task.getTime());
                    synchronized (task) {
                        task.setStatus("done");
                        task.notify();
                    }
                } catch (InterruptedException e) {
                    System.out.println("Worker Error!");
                }
            }, "WorkerV2").run();
        }

    }

}
