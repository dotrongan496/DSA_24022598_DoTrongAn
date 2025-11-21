#ifndef DEFLINKEDLIST_H_INCLUDED
#define DEFLINKEDLIST_H_INCLUDED
#include <iostream>

using namespace std;
//Dinh nghia Node truoc
struct Node{
    int data;
    Node *next;
};

//Dinh nghia Linked List
struct LinkedList{
    Node *head;

//Ham khoi tao, khoi tao con tro head tro toi null
    LinkedList(){
        head = nullptr;
    }
    //Ham huy
    ~LinkedList() {
        Node *h = head;
        while (h != nullptr) {
            Node *temp = h;
            h = h->next;
            delete temp;
        }
        head = nullptr;
    }
    //O(n)
    void TruyCap(int index){
        Node *h = head;
        if(index <= 0){
            cout << "Invalid index" << endl;
            return;
        } else {
            for(int i = 1; h != nullptr && i < index; i++){
                h = h -> next;
            }
        }
        if(h == nullptr){
            cout << "Invalid index" << endl;
            return;
        } else {
            cout << h -> data << endl;
            return;
        }
    }
    //O(1)
    void ThemVaoDau(int value){
        Node *newNode = new Node{value, head};
        head = newNode;
    }
    //O(n)
    void ThemVaoCuoi(int value){
        Node *newNode = new Node{value, nullptr};
        if(head == nullptr){
            head = newNode;
        } else {
            Node *h = head;
            while(h -> next != nullptr){
                h = h -> next;
            }
            h -> next = newNode;
        }
    }
    //O(n)
    void ThemVaoViTri(int index, int value){
        if(index <= 0){
            cout << "Invalid index!" << endl;
            return;
        }
        if(index == 1){
            ThemVaoDau(value);
            return;
        }
        if(head == nullptr){
            ThemVaoDau(value);
            return;
        } else {
            Node *h = head;
            for(int i = 2; h != nullptr && i < index; i++){
                h = h -> next;
            }
            if(h == nullptr){
                cout << "Invalid index!" << endl;
                return;
            } else {
                Node *newNode = new Node{value, h -> next};
                h -> next = newNode;
            }
        }
    }
    //O(1)
    void XoaDau(){
        if(head == nullptr){
            cout << "Can not delete!" << endl;
            return;
        }

        Node *h = head;
        head = head -> next;
        delete h;
    }
    //O(n)
    void XoaCuoi(){
        if(head == nullptr){
            cout << "Can not delete!" << endl;
        } else if(head -> next == nullptr) {
            delete head;
            head = nullptr;
            return;
        } else {
            Node *h = head;
            while(h -> next -> next != nullptr){
                h = h -> next;
            }
            delete h -> next;
            h -> next = nullptr;
        }
    }
    //O(n)
    void XoaViTri(int index){
        if(index <= 0){
            cout << "Invalid index!" << endl;
            return;
        }
        if(head == nullptr){
            cout << "Can not delete!" << endl;
            return;
        }
        if(index == 1){
            XoaDau();
            return;
        } else {
            Node *h = head;
            for(int i = 2; h != nullptr && i < index; i++){
                h = h -> next;
            }
            if(h == nullptr || h -> next == nullptr){
                cout << "Invalid index!" << endl;
                return;
            } else {
                Node *t = h -> next;
                h -> next = t -> next;
                delete t;
            }
        }
    }
    //O(n)
    void DuyetXuoi(){
        Node *h = head;
        if(h == nullptr){
            cout << "Nothing in linked list!" << endl;
            return;
        } else {
            while(h != nullptr){
                cout << h -> data << " ";
                h = h -> next;
            }
        }
        cout<<endl;
    }

    //O(n)
    //Ham chinh de duyet nguoc
    void PrintReverse(Node *h){
        if(h == nullptr){
            return;
        } else {
            PrintReverse(h -> next);
            cout << h -> data << " ";
        }
    }
    //Ham phu de duyet nguoc
    void DuyetNguoc(){
        Node *h = head;
        if(h == nullptr){
            cout<<"Nothing in linked list!" << endl;
            return;
        } else {
            PrintReverse(h);
            cout << endl;
        }
    }

    bool TimKiem(int value){
        Node *h = head;
        while(h != nullptr){
            if(h->data == value){
                return true;
            }
            h = h->next;
        }
        return false;
    }

    void XoaGiaTri(int value){
        if(head == nullptr){
            return;
        }
        if(head->data == value){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        //Truong hop xoa vi tri hoac xoa cuoi
        Node *h = head;
        Node *current = head->next;
        while(current != nullptr && current->data != value){
            h = current;
            current = current->next;
        }
        //Neu current != nullptr nhung current->data == value
        if(current != nullptr){
            h->next = current->next;
            delete current;
        }
    }

};

#endif // DEFLINKEDLIST_H_INCLUDED
