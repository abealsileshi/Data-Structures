#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <string>

using namespace std;

class MaxHeap{
    private:
        int * heap; //pointer to array of elements in heap
        int capacity;
        void maxHeapify(int array[], int index, int size);
    public:
        void buildHeap(int array[], int size);
};

#endif



// class MinHeap{
//    public:
//         MinHeap(int capacity); ~MinHeap();
//         void push(int k); // insert int pop(); // extracMin
//         int peek() { return heap[0]; } void printHeap();
//    private:

//         int *heap; // pointer to array of elements in heap
//         int capacity; // maximum possible size of min heap
//         int currentSize; // Current number of elements in min heap void MinHeapify(int index);
//         int parent(int i) { return (i-1)/2; }
//         int left(int i) { return (2*i+1); }
//         int right(int i) { return (2*i + 2); }
//         void swap(int &x, int &y);
// };