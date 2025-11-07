#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* _insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = _insert(node->left, key);
        } else if (key > node->key) {
            node->right = _insert(node->right, key);
        }

        return node;
    }

    Node* _search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return _search(node->left, key);
        } else {
            return _search(node->right, key);
        }
    }

    Node* _findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* _deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = _deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = _deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = _findMin(node->right);
            node->key = temp->key;
            node->right = _deleteNode(node->right, temp->key);
        }
        return node;
    }

    void _inorder(Node* node) {
        if (node != nullptr) {
            _inorder(node->left);
            cout << node->key << " ";
            _inorder(node->right);
        }
    }

    void _preorder(Node* node) {
        if (node != nullptr) {
            cout << node->key << " ";
            _preorder(node->left);
            _preorder(node->right);
        }
    }

    void _postorder(Node* node) {
        if (node != nullptr) {
            _postorder(node->left);
            _postorder(node->right);
            cout << node->key << " ";
        }
    }

    void _destroyTree(Node* node) {
        if (node) {
            _destroyTree(node->left);
            _destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        _destroyTree(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    bool search(int key) {
        return _search(root, key) != nullptr;
    }

    void deleteNode(int key) {
        root = _deleteNode(root, key);
    }

    void inorder() {
        _inorder(root);
        cout << endl;
    }

    void preorder() {
        _preorder(root);
        cout << endl;
    }

    void postorder() {
        _postorder(root);
        cout << endl;
    }
};

// --- Hàm main để chạy thử ---
int main() {
    BinarySearchTree bst;

    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int key : keys) {
        bst.insert(key);
    }

    cout << "Duyet Inorder:   ";
    bst.inorder();
    cout << "Duyet Preorder:  ";
    bst.preorder();
    cout << "Duyet Postorder: ";
    bst.postorder();
    cout << "--------------------" << endl;

    int keyToFind = 40;
    if (bst.search(keyToFind)) {
        cout << "Tim thay nut co gia tri: " << keyToFind << endl;
    } else {
        cout << "Khong tim thay nut co gia tri: " << keyToFind << endl;
    }

    keyToFind = 99;
    if (bst.search(keyToFind)) {
        cout << "Tim thay nut co gia tri: " << keyToFind << endl;
    } else {
        cout << "Khong tim thay nut co gia tri: " << keyToFind << endl;
    }
    cout << "--------------------" << endl;

    cout << "Xoa nut 20 (nut la)..." << endl;
    bst.deleteNode(20);
    cout << "Inorder sau khi xoa 20: ";
    bst.inorder();

    cout << "Xoa nut 30 (1 con)..." << endl;
    bst.deleteNode(30);
    cout << "Inorder sau khi xoa 30: ";
    bst.inorder();

    cout << "Xoa nut 50 (2 con - goc)..." << endl;
    bst.deleteNode(50);
    cout << "Inorder sau khi xoa 50: ";
    bst.inorder();

    return 0;
}
