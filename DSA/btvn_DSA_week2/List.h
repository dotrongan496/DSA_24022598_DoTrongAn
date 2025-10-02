#ifndef LIST_H
#define LIST_H
#include <iostream>
const int MAX_list = 100;
using namespace std;
class List {
public:

    int coutn;
    int arr[MAX_list];

    List() {
        coutn = 0;
    }

    // Truy cập phần tử O(1)
    int access_List(int index) {
        if (index > MAX_list || index <= 0) return -1;
        if (index <= coutn) {
            return arr[index - 1];
        } else return 0;
    }

    // Thêm vào đầu O(n)
    bool addFirst(int num) {
        if (coutn == MAX_list)
            return false;
        for (int i = coutn; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = num;
        coutn++;
        return true;
    }

    // Thêm vào cuối O(1)
    bool addLast(int num) {
        if (coutn == MAX_list)
            return false;
        arr[coutn] = num;
        coutn++;
        return true;
    }

    // Thêm vào vị trí pos O(n)
    bool addPos(int pos, int num) {
        if (coutn == MAX_list || pos <= 0 || pos > coutn + 1)
            return false;
        for (int i = coutn; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = num;
        coutn++;
        return true;
    }

    // Xóa phần tử đầu O(n)
    bool deleteFirst() {
        if (coutn == 0) return false;
        for (int i = 0; i < coutn - 1; i++) {
            arr[i] = arr[i + 1];
        }
        coutn--;
        return true;
    }

    // Xóa phần tử cuối O(1)
    bool deleteLast() {
        if (coutn == 0) return false;
        coutn--;
        return true;
    }

    // Xóa phần tử tại vị trí pos O(n)
    bool deletePos(int pos) {
        if (pos <= 0 || pos > coutn) return false;
        for (int i = pos - 1; i < coutn - 1; i++) {
            arr[i] = arr[i + 1];
        }
        coutn--;
        return true;
    }

    // In xuôi O(n)
    void print() {
        for (int i = 0; i < coutn; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // In ngược O(n)
    void reversePrint() {
        for (int i = coutn - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#endif
