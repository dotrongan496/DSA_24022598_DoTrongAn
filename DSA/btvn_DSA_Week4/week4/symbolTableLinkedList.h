#ifndef SYMBOLTABLELINKLIST_H
#define SYMBOLTABLELINKLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;

    Node(string k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class SymbolTable {
private:
    Node* head;

public:
    SymbolTable() {
        head = nullptr;
    }

    void insert(string key, int value) {
        Node* temp = head;
        // Nếu tồn tại thì cập nhật value O(n)
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                cout << "Cập nhật key \"" << key << "\" với value mới.\n";
                return;
            }
            temp = temp->next;
        }

        // Nếu chưa tồn tại thì thêm node mới vào đầu danh sách O(1)
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        cout << "Đã thêm key \"" << key << "\" với value = " << value << ".\n";
    }
    //O(n)
    int get(string key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return -1;
    }

    // Xóa một key khỏi bảng O(n)
    void remove(string key) {
        if (head == nullptr) return;
        if (head->key == key) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Đã xóa key \"" << key << "\".\n";
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->key == key) {
                prev->next = curr->next;
                delete curr;
                cout << "Đã xóa key \"" << key << "\".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Không tìm thấy key ";;
    }

    // In toàn bộ bảng
    void print() {
        if (head == nullptr) {
            cout << "Bảng rỗng\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Key: " << temp->key << " | Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    ~SymbolTable() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
