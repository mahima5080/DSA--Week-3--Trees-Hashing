#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

class HashMapLinearProbing {
private:
    int table[SIZE];
    bool isOccupied[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashMapLinearProbing() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
            isOccupied[i] = false;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        // Linear Probing for Collision Handling
        while (isOccupied[index]) {
            index = (index + 1) % SIZE;
            if (index == originalIndex) {
                cout << "❌ Hash Table is Full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        isOccupied[index] = true;
        cout << "✅ Inserted key " << key << " at index " << index << endl;
    }

    void display() {
        cout << "\n------------------------------------------" << endl;
        cout << "            HASH TABLE CONTENTS           " << endl;
        cout << "------------------------------------------" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (isOccupied[i]) {
                cout << "Index [" << i << "] -> " << table[i] << endl;
            } else {
                cout << "Index [" << i << "] -> EMPTY" << endl;
            }
        }
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    HashMapLinearProbing ht;

    // Keys generating collisions (e.g., 12, 22, 32 all map to index 2)
    ht.insert(12);
    ht.insert(25);
    ht.insert(35);
    ht.insert(22);
    ht.insert(32);

    ht.display();

    return 0;
}
