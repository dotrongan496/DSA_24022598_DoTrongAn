#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include "DefLinkedList.h"

using namespace std;

struct HashTableSC {
    int TABLE_SIZE;
    LinkedList *table; //Mang c�c danh sach lien ket

    //Ham bam
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    //Constructor
    HashTableSC(int size) {
        TABLE_SIZE = size;
        //Cap phat mot mang gom size cai LinkedList
        table = new LinkedList[TABLE_SIZE];
    }

    //Destructor
    ~HashTableSC() {
        delete[] table;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].ThemVaoDau(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].XoaGiaTri(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        return table[index].TimKiem(key);
    }

    //Ham hien thi
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* h = table[i].head;
            if (h == nullptr) {
                cout << "NULL";
            } else {
                while (h != nullptr) {
                    cout << h->data << " -> ";
                    h = h->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

#endif // HASHTABLE_H_INCLUDED
