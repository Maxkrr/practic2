// Хэш-таблицы:
#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;

class HashTable {
    vector<list<pair<int, int>>> table;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) : capacity(size) {
        table.resize(size);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto &kvp : table[index]) {
            if (kvp.first == key) {
                kvp.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int search(int key) {
        int index = hashFunction(key);
        for (auto &kvp : table[index]) {
            if (kvp.first == key) {
                return kvp.second;
            }
        }
        return -1; // не найдено
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(1, 10);
    cout << ht.search(1) << endl; // 10
    ht.remove(1);
    cout << ht.search(1) << endl; // -1
    return 0;
}
// Куча Фибоначчи:
struct Node {
    int key, degree;
    Node *left, *right, *child, *parent;
    Node(int k) : key(k), degree(0), left(this), right(this), child(nullptr), parent(nullptr) {}
};

struct FibHeap {
    Node* min = nullptr;

    void insert(Node* x) {
        if (!min) min = x;
        else {
            x->left = min;
            x->right = min->right;
            min->right->left = x;
            min->right = x;
            if (x->key < min->key) min = x;
        }
    }

    int extractMin() {
        Node* z = min;
        if (!z) return -1;
        if (z->child) {
            Node* c = z->child;
            do {
                c->parent = nullptr;
                c = c->right;
            } while (c != z->child);
            // Пропущено объединение детей с корнями
        }
        z->left->right = z->right;
        z->right->left = z->left;
        min = (z == z->right) ? nullptr : z->right;
        int ret = z->key;
        delete z;
        return ret;
    }
};

