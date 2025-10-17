
#ifndef SYMBOLTABLELIST_H
#define SYMBOLTABLELIST_H

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

class SymbolTableList {
private:
    List values;
    char keys[100];
    int size;

public:
    SymbolTableList() {
        size = 0;
    }

    void insert(char key, int value) {
        int posKey = findPosKey(key);
        if (posKey == -1 ) {
            values.addLast(value);
            Keys[size] = key;
            size++;
        }
        else {
            values.addLast();
            keys(size) = key;
            size++;
        }
    }

    int get(char key, int value) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key)
                return values.accessList(i);
        }
        cout << "Không tìm thấy key " << key << endl;
        return -1;
    }

    void printf() {
        for (int i = 0; i < size; i++) {
            cout << "Key: " << keys[i] << " | Value: " << values.accessList(i) << endl;
        }
    }
    // O(log n)
    int findPosKey(int value){
        int left = 0;
        int right = size;
        mid = (left + right)/2;
        bool timthay = false;
        while(timthay != true){

                if (mid == left && mid == right){}
                timthay = true;
                return -1;

            if (keys[mid] == value) {
            timthay = true;
            return mid;
            }
            else if (keys[mid] < value) {
                int left = mid + 1;
                int right = right;
                mid = (left + right)/2;
            }
            else if (keys[mid] > value) {
                int left = left;
                int right = mid - 1;
                mid = (left + right)/2;
            }
        }
    }

    void remove(char key, int value){
        int pos = findPosKey(key);
        for (int i = pos; i <= size ; i++){
            keys[i] = keys[i+1];
        }
        size - 1;
        values.deletePos(pos);
    }
};

#endif // SYMBOLTABLELIST_H

