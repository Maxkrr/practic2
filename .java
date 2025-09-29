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
class Node {
    int key, degree;
    Node left, right, child, parent;
    Node(int k) {
        key = k;
        degree = 0;
        left = right = this;
    }
}

class FibHeap {
    Node min = null;

    void insert(Node x) {
        if (min == null) min = x;
        else {
            x.left = min;
            x.right = min.right;
            min.right.left = x;
            min.right = x;
            if (x.key < min.key) min = x;
        }
    }

    Integer extractMin() {
        Node z = min;
        if (z == null) return null;
        if (z.child != null) {
            Node c = z.child;
            do {
                c.parent = null;
                c = c.right;
            } while (c != z.child);
            // Дети не объединены с корнями для краткости
        }
        z.left.right = z.right;
        z.right.left = z.left;
        min = (z == z.right) ? null : z.right;
        return z.key;
    }
}
