
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <bits/stdc++.h>
using namespace std;

struct MinHeap {
    vector<pair<int,int>> heap; // {key, vertex}

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }

    void swim(int i) {
        while (i > 0 && heap[i].first < heap[parent(i)].first) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void sink(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l].first < heap[smallest].first) smallest = l;
        if (r < heap.size() && heap[r].first < heap[smallest].first) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            sink(smallest);
        }
    }

    void push(pair<int,int> val) {
        heap.push_back(val);
        swim(heap.size() - 1);
    }

    pair<int,int> top() {
        if (heap.empty()) {
            throw runtime_error("MinHeap::top() called on empty heap");
        }
        return heap[0];
    }

    void pop() {
        if (heap.empty()) return;
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        sink(0);
    }

    bool empty() const {
        return heap.empty();
    }

    bool empty() {
        return heap.empty();
    }
};

#endif

