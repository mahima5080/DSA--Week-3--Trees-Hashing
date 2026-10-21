#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void search(int key) {
        if (search(root, key)) {
            cout << "✅ Value " << key << " found in BST!" << endl;
        } else {
            cout << "❌ Value " << key << " NOT found in BST." << endl;
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    bst.search(30);
    bst.search(100);

    return 0;
}
