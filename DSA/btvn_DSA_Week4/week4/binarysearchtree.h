#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;

    BST() {
        root = nullptr;
    }

    // O(log n), max: O(n)
    void insertt(Node*& r, int value) {
        if (r == nullptr) {
            r = new Node{value, nullptr, nullptr};
            return;
        }
        if (value < r->data)
            insertt(r->left, value);
        else if (value > r->data)
            insertt(r->right, value);

    }

    void insert(int value) {
        insertt(root, value);
    }

    //Root -> Left -> Right ---
    void preorderr(Node* r) {
        if (r == nullptr) return;
        cout << r->data << " ";
        preorderr(r->left);
        preorderr(r->right);
    }

    void preorder() {
        if (root == nullptr) return;
        cout << "Preorder (Root -> Left -> Right): ";
        preorderr(root);
        cout << endl;
    }

    //Left -> Root -> Right
    void inorderr(Node* r) {
        if (r == nullptr) return;
        inorderr(r->left);
        cout << r->data << " ";
        inorderr(r->right);
    }

    void inorder() {
        if (root == nullptr) return;
        cout << "Inorder (Left -> Root -> Right): ";
        inorderr(root);
        cout << endl;
    }

    // Left -> Right -> Root
    void postorderr(Node* r) {
        if (r == nullptr) return;
        postorderr(r->left);
        postorderr(r->right);
        cout << r->data << " ";
    }

    void postorder() {
        if (root == nullptr) return;
        cout << "Postorder (Left -> Right -> Root): ";
        postorderr(root);
        cout << endl;
    }
};

#endif // BINARYSEARCHTREE_H

