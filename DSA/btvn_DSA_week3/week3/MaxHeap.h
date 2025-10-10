#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <bits/stdc++.h>
using namespace std;

class MaxBinaryHeap {
private:
    vector<int> heap;

    void swapp(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void swim(int k) {
        while (k > 0 && heap[(k - 1) / 2] < heap[k]) {
            int parent_index = (k - 1) / 2;
            swapp(k, parent_index);
            k = parent_index;
        }
    }

    void sink(int k) {
        int N = size();
        while (true) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int largest = k;

            if (left < N && heap[left] > heap[largest]) largest = left;
            if (right < N && heap[right] > heap[largest]) largest = right;

            if (largest == k) break;

            swapp(k, largest);
            k = largest;
        }
    }

public:
    int size() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int getMax() const {
        if (isEmpty()) {
            cout << "Heap rong\n";
            return -1;
        }
        return heap[0];
    }

    void insert(int data) {
        heap.push_back(data);
        swim(size() - 1);
    }

    int delMax() {
        if (isEmpty()) {
            cout << "Heap rong\n";
            return -1;
        }

        int maxVal = heap[0];
        swapp(0, size() - 1);
        heap.pop_back();

        if (!isEmpty()) sink(0);

        return maxVal;
    }
};

#endif // MAXHEAP_H
