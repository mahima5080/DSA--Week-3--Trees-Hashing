#include <iostream>
#include <string>
using namespace std;

struct ContactNode {
    String name;
    String phone;
    ContactNode* left;
    ContactNode* right;

    ContactNode(string n, string p) : name(n), phone(p), left(nullptr), right(nullptr) {}
};

class ContactDirectory {
private:
    ContactNode* root;

    ContactNode* insert(ContactNode* node, string name, string phone) {
        if (node == nullptr) return new ContactNode(name, phone);
        if (name < node->name) {
            node->left = insert(node->left, name, phone);
        } else if (name > node->name) {
            node->right = insert(node->right, name, phone);
        } else {
            cout << "⚠️ Contact with name " << name << " already exists." << endl;
        }
        return node;
    }

    ContactNode* findMin(ContactNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    ContactNode* deleteContact(ContactNode* node, string name) {
        if (node == nullptr) return nullptr;

        if (name < node->name) {
            node->left = deleteContact(node->left, name);
        } else if (name > node->name) {
            node->right = deleteContact(node->right, name);
        } else {
            // Case 1 & 2: 0 or 1 child
            if (node->left == nullptr) {
                ContactNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                ContactNode* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: 2 children
            ContactNode* temp = findMin(node->right);
            node->name = temp->name;
            node->phone = temp->phone;
            node->right = deleteContact(node->right, temp->name);
        }
        return node;
    }

    void search(ContactNode* node, string name) {
        if (node == nullptr) {
            cout << "❌ Contact '" << name << "' NOT found." << endl;
            return;
        }
        if (node->name == name) {
            cout << "✅ Found Contact -> Name: " << node->name << " | Phone: " << node->phone << endl;
            return;
        }
        if (name < node->name) search(node->left, name);
        else search(node->right, name);
    }

    void displayAlphabetical(ContactNode* node) {
        if (node == nullptr) return;
        displayAlphabetical(node->left);
        cout << "📞 Name: " << node->name << " \t| Phone: " << node->phone << endl;
        displayAlphabetical(node->right);
    }

public:
    ContactDirectory() : root(nullptr) {}

    void addContact(string name, string phone) {
        root = insert(root, name, phone);
        cout << "✅ Contact added: " << name << endl;
    }

    void removeContact(string name) {
        root = deleteContact(root, name);
        cout << "🗑️ Processed deletion for: " << name << endl;
    }

    void searchContact(string name) {
        search(root, name);
    }

    void showAllAlphabetically() {
        cout << "\n------------------------------------------" << endl;
        cout << "       CONTACT DIRECTORY (ALPHABETICAL)   " << endl;
        cout << "------------------------------------------" << endl;
        if (root == nullptr) {
            cout << "Directory is empty." << endl;
        } else {
            displayAlphabetical(root);
        }
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    ContactDirectory directory;

    cout << "==========================================" << endl;
    cout << "     BST CONTACT DIRECTORY SIMULATION     " << endl;
    cout << "==========================================" << endl;

    directory.addContact("Mahima", "9876543210");
    directory.addContact("Aarav", "9123456789");
    directory.addContact("Rohan", "9988776655");
    directory.addContact("Ananya", "9554433221");

    directory.showAllAlphabetically();

    directory.searchContact("Mahima");
    directory.searchContact("Siddharth");

    directory.removeContact("Rohan");
    directory.showAllAlphabetically();

    return 0;
}
