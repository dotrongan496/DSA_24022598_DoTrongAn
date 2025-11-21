#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    //Constructor
    AVLNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

struct AVLTree {
    AVLNode *root;

    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Destructor
    ~AVLTree() {
        destroyTree(root);
    }

    //Lay chieu cao
    int getHeight(AVLNode *node) {
        if (node == nullptr){
            return 0;
        }
        return node->height;
    }

    //Lay he so can bang
    int getBalanceFactor(AVLNode *node) {
        if (node == nullptr){
            return 0;
        }
        return getHeight(node->right) - getHeight(node->left);
    }

    //Cap nhat chieu cao cho mot node
    void updateHeight(AVLNode *node) {
        if (node != nullptr) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    //Tim node nho nhat de dung cho ham xoa node
    AVLNode* findMin(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    //Xoay phai
    AVLNode* rightRotate(AVLNode *y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        //Cap nhat chieu cao y truoc roi x
        updateHeight(y);
        updateHeight(x);

        //Tra ve goc moi la x
        return x;
    }

    //Xoay trai
    AVLNode* leftRotate(AVLNode *x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        //Cap nhat chieu cao x truoc roi y
        updateHeight(x);
        updateHeight(y);

        //Tra ve goc moi la y
        return y;
    }

    //Destructor cho cac node
    void destroyTree(AVLNode *node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    //Duyet cay
    void printInOrder(AVLNode *node) {
        if (node != nullptr) {
            printInOrder(node->left);
            cout << node->key << "(h=" << node->height << ") ";
            printInOrder(node->right);
        }
    }

    //Chen node vao cay
    AVLNode* insertt(AVLNode *node, int key) {
        //Chen nhu BST o doan nay
        if (node == nullptr) {
            return new AVLNode(key);
        }
        if (key < node->key) {
            node->left = insertt(node->left, key);
        } else if (key > node->key) {
            node->right = insertt(node->right, key);
        } else {
            return node;
        }
        //Cap nhat chieu cao cay cho node va lay he so can bang
        updateHeight(node);
        int balance = getBalanceFactor(node);

        //Left-Left
        if (balance < -1 && key < node->left->key) {
            return rightRotate(node);
        }
        // Right-Right
        if (balance > 1 && key > node->right->key) {
            return leftRotate(node);
        }
        // Left-Right
        if (balance < -1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right-Left
        if (balance > 1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    //Xoa node cho cay
    AVLNode* removee(AVLNode *node, int key) {
        //Xoa nhu BST o doan nay
        if (node == nullptr){
            return node;
        }
        if (key < node->key) {
            node->left = removee(node->left, key);
        } else if (key > node->key) {
            node->right = removee(node->right, key);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode *temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                AVLNode *temp = findMin(node->right);
                node->key = temp->key;
                node->right = removee(node->right, temp->key);
            }
        }

        if (node == nullptr) return node;

        //Cap nhat chieu cao cay cho node va lay he so can bang
        updateHeight(node);
        int balance = getBalanceFactor(node);

        // Left-Left
        if (balance < -1 && getBalanceFactor(node->left) <= 0) {
            return rightRotate(node);
        }
        // Right-Right
        if (balance > 1 && getBalanceFactor(node->right) >= 0) {
            return leftRotate(node);
        }
        // Right-Left
        if (balance > 1 && getBalanceFactor(node->right) < 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // Left-Right
        if (balance < -1 && getBalanceFactor(node->left) > 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        return node;
    }

    void insert(int key) {
        root = insertt(root, key);
    }

    void remove(int key) {
        root = removee(root, key);
    }

    //Ham hien thi
    void display() {
        cout << "Cay (In-Order): ";
        printInOrder(root);
        cout << endl;
    }
};


#endif // AVL_H
