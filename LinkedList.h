#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    int count;

    LinkedList() {
        head = nullptr;
        count = 0;
    }

    // Truy cập phần tử O(n)
    int accessLinkedList(int index) {
        if (index < 0 || index >= count)
            return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Thêm vào đầu O(1)
    void addFirst(int value) {
        Node* newtemp = new Node;
        newtemp->data = value;
        newtemp->next = head;
        head = newtemp;
        count++;
    }

    // Thêm vào cuối O(n)
    void addLast(int value) {
        Node* newtemp = new Node;
        newtemp->data = value;
        newtemp->next = nullptr;

        if (head == nullptr) {
            head = newtemp;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newtemp;
        }
        count++;
    }

    // Thêm vào vị trí pos O(n)
    void addPos(int pos, int value) {
        if (pos < 0 || pos > count) {
            cout << "Vi tri khong hop le" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    // Xóa phần tử đầu O(1)
    void deleteFirst() {
        if (head == nullptr) {
            cout << "Danh sach rong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    // Xóa phần tử cuối O(n)
    void deleteLast() {
        if (head == nullptr) {
            cout << "Danh sach rong" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            for (int i = 0; i < count - 2; i++) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        count--;
    }

    // In xuôi O(n)
    void print() {
        if (head == nullptr) {
            cout << "Danh sach rong" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // In ngược O(n)
    void reverseprint() {
        if (head == nullptr) {
            cout << "Danh sach rong" << endl;
            return;
        }
        int arr[1000];
        Node* temp = head;
        int i = 0;
        while (temp != nullptr) {
            arr[i++] = temp->data;
            temp = temp->next;
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << arr[j] << " <- ";
        }
        cout << "NULL";
    }
};

#endif
