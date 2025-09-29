// Хэш-таблицы:
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();

        map.put(1, "apple");
        System.out.println(map.get(1)); // apple

        map.remove(1);
        System.out.println(map.get(1)); // null
    }
}
// Куча Фибоначчи:
