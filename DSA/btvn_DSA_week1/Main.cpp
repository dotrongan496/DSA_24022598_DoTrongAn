#include <bits/stdc++.h>
#include "List.h"
#include "Stack.h"
#include "LinkedList.h"
using namespace std;


int main() {
    List list;

    list.addFirst(24);
    list.addFirst(3);
    list.addLast(10);
    list.addLast(20);
    list.addFirst(5);
    list.addPos(2, 15);

    list.print();

    list.reversePrint();

    int n;
    cout << "Nhập vị trí cần truy cập: ";
    cin >> n;
    cout << "Phần tử ở vị trí " << n << ": " << list.access_List(n) << endl;

    cout << "LINEKD LIST" << endl;

    LinkedList linkedList;
    linkedList.addFirst(24);
    linkedList.addFirst(3);
    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    linkedList.addPos(2, 15);

    linkedList.print();
    linkedList.reverseprint();

    return 0;
}
