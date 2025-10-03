#ifndef LIST_H
#define LIST_H
#include <iostream>
const int MAX_list = 100;
using namespace std;
class List {
public:

    int count;
    int arr[MAX_list];

    List() {
        count = 0;
    }

    // Truy cập phần tử O(1)
    int accessList(int index) {
        if (index > MAX_list || index <= 0) return -1;
        if (index <= count) {
            return arr[index - 1];
        } else return 0;
    }

    // Thêm vào đầu O(n)
    bool addFirst(int num) {
        if (count == MAX_list)
            return false;
        for (int i = count; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = num;
        count++;
        return true;
    }

    // Thêm vào cuối O(1)
    bool addLast(int num) {
        if (count == MAX_list)
            return false;
        arr[count] = num;
        count++;
        return true;
    }

    // Thêm vào vị trí pos O(n)
    bool addPos(int pos, int num) {
        if (count == MAX_list || pos <= 0 || pos > count + 1)
            return false;
        for (int i = count; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = num;
        count++;
        return true;
    }

    // Xóa phần tử đầu O(n)
    bool deleteFirst() {
        if (count == 0) return false;
        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
        return true;
    }

    // Xóa phần tử cuối O(1)
    bool deleteLast() {
        if (count == 0) return false;
        count--;
        return true;
    }

    // Xóa phần tử tại vị trí pos O(n)
    bool deletePos(int pos) {
        if (pos <= 0 || pos > count) return false;
        for (int i = pos - 1; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
        return true;
    }

    // In xuôi O(n)
    void print() {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // In ngược O(n)
    void reversePrint() {
        for (int i = count - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#endif
