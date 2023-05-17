import java.util.HashMap;
import java.util.Map;

public class GameKata {

  public static void run(String[] tito, String[] wiwid) {
    Map<String, Integer> map = new HashMap<String, Integer>();
    String[] mutual = new String[tito.length];

    for (int i = 0; i < tito.length; i++) {
      map.put(tito[i], i);
    }

    int j = 0;
    for (String kataWiwid : wiwid) {
      if (map.containsKey(kataWiwid)) {
        mutual[j++] = kataWiwid;
        System.out.println(kataWiwid);
      }
    }

  }

  public static void main(String[] args) {
    String tito = "Budi Budi adalah Budi";
    String wiwid = "Budi Adalah bola";

    String[] titosplit = tito.split(" ");
    String[] wiwidsplit = wiwid.split(" ");

    run(titosplit, wiwidsplit);
  }
}
