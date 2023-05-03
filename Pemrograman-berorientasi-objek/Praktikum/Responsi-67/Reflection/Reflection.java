package Reflection;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection {
    // TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT
    // TYPENYA
    // BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    // DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() {
        ArrayList<String> ret = new ArrayList<String>();
        try {
            Class<?> ghost = Class.forName("Ghost");
            Method[] methods = ghost.getDeclaredMethods();

            for (Method method : methods) {
                method.setAccessible(true);
                ret.add(method.getName());
            }
        } catch (Exception e) {

        }
        return ret;
    }

    public Integer sumGhost() throws Exception {
        ArrayList<String> methods = this.ghostMethods();
        int ret = 0;

        Class<?> ghost = Class.forName("Ghost");
        Object ghostObject = ghost.getDeclaredConstructors()[0].newInstance();

        for (String methodInfo : methods) {
            Method method = ghost.getDeclaredMethod(methodInfo);
            method.setAccessible(true);
            if (method.getReturnType() == Integer.class) {
                ret += (Integer) method.invoke(ghostObject);
            }
        }
        return ret;
    }

    public String letterGhost() throws Exception {
        ArrayList<String> methods = this.ghostMethods();
        String ret = "";

        Class<?> ghost = Class.forName("Ghost");
        Object ghostObject = ghost.getDeclaredConstructors()[0].newInstance();

        for (String methodInfo : methods) {
            Method method = ghost.getDeclaredMethod(methodInfo);
            method.setAccessible(true);
            if (method.getReturnType() == String.class) {
                ret += (String) method.invoke(ghostObject);
            }
        }

        return ret;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        boolean found = false;
        String ret = "NaN";

        for (int i = 0; i < sl.size() && !found; i++) {
            Secret secret = sl.get(i);
            if (secret.isThis(email)) {
                found = true;
                Field field = secret.getClass().getDeclaredField("uniqueId");
                field.setAccessible(true);
                ret = (String) field.get(secret);
            }
        }
        return ret;
    }
}
