
#include <iostream>
#include "DefLinkedList.h"
#include "HashTable.h"

using namespace std;

int main() {
    int tableSize = 10;
    HashTableSC ht_sc(tableSize);

    ht_sc.insert(10);
    ht_sc.insert(20);
    ht_sc.insert(5);
    ht_sc.insert(15);

    ht_sc.display();

    cout << (ht_sc.search(15) ? "Tim thay" : "Khong tim thay") << endl;

    ht_sc.remove(15);

    cout << (ht_sc.search(15) ? "Tim thay" : "Khong tim thay") << endl;

    ht_sc.display();

    return 0;
}
