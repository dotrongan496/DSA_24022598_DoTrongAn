#include <bits/stdc++.h>
#include "priorityqueue.h"
#include "MaxHeap.h"

using namespace std;

int main(){

    MaxBinaryHeap heap;

    heap.insert(50);
    heap.insert(30);
    heap.insert(70);
    heap.insert(10);
    heap.insert(60);

    cout << "kich thuoc: " << heap.size() << endl;
    cout << "Max data " << heap.getMax() << endl;

    cout << "delete Max: " << heap.delMax() << endl;
    cout << "new Max data: " << heap.getMax() << endl;

    cout << "delete Max: " << heap.delMax() << endl;
    cout << "kich thuoc moi: " << heap.size() << endl;

    return 0;
}

