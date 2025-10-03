#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;


int main() {
    StackLinkedList st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack hien tai: ";
    st.print();  // 30 -> 20 -> 10 -> NULL

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;   // 30

    cout << "Stack sau khi pop: ";
    st.print();  // 20 -> 10 -> NULL

    cout << "Top moi: " << st.top() << endl;  // 20
    cout << "Size: " << st.size() << endl;    // 2
    cout << (st.isEmpty() ? "Stack rong" : "Stack khong rong") << endl;

}
