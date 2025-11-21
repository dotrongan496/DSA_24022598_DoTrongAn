
#include <iostream>
#include "AVL.h"

using namespace std;

int main() {

    cout << "AVL Tree Test" << endl;
    AVLTree tree;

    cout << "\n Test chen" << endl;
    cout << "\nChen 30, 20, 10 (Test LL Case)..." << endl;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.display();

    cout << "\nChen 40, 50 (Test RR Case)..." << endl;
    tree.insert(40);
    tree.insert(50);

    tree.display();

    cout << "\nChen 5 (Test LR Case)..." << endl;
    tree.insert(5);
    tree.display();

    cout << "\nChen 7 (Test LR Case)..." << endl;
    tree.insert(7);

    tree.display();

    cout << "\nTest xoa" << endl;
    AVLTree tree2;
    tree2.insert(9);
    tree2.insert(5);
    tree2.insert(10);
    tree2.insert(0);
    tree2.insert(6);
    tree2.insert(11);
    tree2.insert(-1);
    tree2.insert(1);
    tree2.insert(2);

    cout << "Cay ban dau:" << endl;
    tree2.display();

    cout << "\nXoa 10" << endl;
    tree2.remove(10);
    tree2.display();

    cout << "\nXoa 11" << endl;
    tree2.remove(11);
    tree2.display();

    cout << "\nXoa 0" << endl;
    tree2.remove(0);
    tree2.display();

    return 0;
}
