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
        return arr.coutn == 0;
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
            int temp = arr.access_List(arr.coutn);
            arr.deleteLast();
            return temp;
        }
    }
    //O(1)
    int size() {
        return (arr.coutn + 1);
    }
    //O(1)
    int top(){
        return arr.access_List(arr.coutn);
    }


};


class Stack_LinkedList {
public:
    LinkedList link_arr;
    //O(1)
    bool isEmpty() {
        if(link_arr.count == 0) {
            return true;
        }
        return false;
    }
    //O(1)
    void push(int item) {
        link_arr.addFirst(item);
    }

    //O(n)
    int pop() {
        if (link_arr.count == 0) {
            cout << "danh sach rong \n";
            return -1;
        }
        int temp = link_arr.access_LinkedList(link_arr.count -1);
        link_arr.deleteLast();
        return temp;
    }

    //o(1)
    int size(){
        return link_arr.count;
    }

    //O(n)
    int top(){
        if (link_arr.count ==0) {
            cout << "danh sach rong \n";
            return -1;
        }
        return link_arr.access_LinkedList(0);
    }
    //O(n)
    void print(){
        link_arr.print();
    }


};

#endif
