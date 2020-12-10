#include <iostream>
#include <cmath>
#include "heapsort.hpp"

using namespace std;




void MaxHeap:: maxHeapify(int array[], int x, int size){
    int left = (2 * x) + 1;
    int right = (2 * x) + 2;
    int largest = 0;
    if(left < size && array[left] > array[x]){
        largest = left;
    }
    else{
        largest = x;
    }
    if(right < size && array[right] > array[largest]){
        largest = right;
    }
    if(largest != x){
        int temp = array[x];
        array[x] = array[largest];
        array[largest] = temp;
        maxHeapify(array, largest, size);
    }
}

void MaxHeap:: buildHeap(int array[], int size){
    int num = floor(size/2);
    num = num -1;
    for(int x = num; x >= 0; x--){
        maxHeapify(array, x, size);
    }
}