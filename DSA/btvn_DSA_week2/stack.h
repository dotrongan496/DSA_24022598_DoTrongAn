#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "LinkedList.h"
using namespace std;

class Stack_List {
public:
    List arr;

    //O(1)
    bool isEmpty(){
        return arr.count == 0;
    }

    //O(1)
    void push(int item){
        arr.addLast(item);
    }

    //O(1)
    int pop(){
        if (isEmpty()){
            cout << "Danh sach rong \n";
            return -1;
        }
        else {
            int temp = arr.accessList(arr.count);
            arr.deleteLast();
            return temp;
        }
    }
    //O(1)
    int size() {
        return (arr.count + 1);
    }
    //O(1)
    int top(){
        return arr.accessList(arr.count);
    }


};


class StackLinkedList {
public:
    LinkedList linkarr;
    //O(1)
    bool isEmpty() {
        if(linkarr.count == 0) {
            return true;
        }
        return false;
    }
    //O(1)
    void push(int item) {
        linkarr.addFirst(item);
    }

    //O(1)
    int pop() {
        if (linkarr.count == 0) {
            cout << "danh sach rong \n";
            return -1;
        }
        int temp = linkarr.accessLinkedList(linkarr.count -1);
        linkarr.deleteFirst();
        return temp;
    }

    //o(1)
    int size(){
        return linkarr.count;
    }

    //O(n)
    int top(){
        if (linkarr.count ==0) {
            cout << "danh sach rong \n";
            return -1;
        }
        return linkarr.accessLinkedList(0);
    }
    //O(n)
    void print(){
        linkarr.print();
    }


};

#endif
