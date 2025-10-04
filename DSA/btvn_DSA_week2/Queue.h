#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"
#include "LinkedList.h"
using namespace std;
class queue_List{
public:
    List arr;

    //O(1)
    bool isEmpty(){
        return (arr.count == 0);
    }
    //O(n)
    void push(int item) {
        arr.addFirst(item);
    }
    //O(1)
    int layra() {
        if (arr.count == 0) {
            cout << "Hang doi rong \n";
            return 0;
        }
        int temp = arr.access_List(arr.count);
        arr.deleteLast();
        return temp;
    }

    //O(1)
    int top(){
        if (arr.count == 0)
            return -1;
        return arr.access_List(arr.count);
    }

    //O(1)
    int size(){
        return arr.count + 1;
    }

    //O(n)
    void print(){
        arr.print();
    }

};


class queue_LinkedList{
public:
    LinkedList link_arr;
    //O(1)
    bool isEmpty(){
        return link_arr.count == 0;
    }
    //O(1)
    void push(int item){
        link_arr.addFirst(item);
    }
    //O(n)
    int layra() {
        if (link_arr.count == 0) {
            cout << "Hang doi rong \n";
            return -1;
        }
        int temp = link_arr.accessLinkedList(link_arr.count -1);
        link_arr.deleteLast();
        return temp;
    }

    //O(1)
    int top(){
        return link_arr.accessLinkedList(link_arr.count - 1);
    }

    //O(1)
    int size(){
        return link_arr.count;
    }

    //O(n)
    void print(){
        link_arr.reverseprint();
    }

};

#endif // QUEUE_H
