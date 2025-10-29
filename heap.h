//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        weightArr[size] = idx;
        size++;
        upheap(size-1,weightArr[]);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        int rootIndex = weightArr[0]; //find the root index
        for (int i = 1; i < size; i++) {
            if (weightArr[i] < rootIndex) {
                rootIndex = weightArr[i];
            }
        }
        //replace root with last element
        weightArr[size-1] = rootIndex;
        size--;
        downheap(size-1,weightArr);
        return rootIndex;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (weightArr[pos] < weightArr[(pos-1)/2] &&  pos > 1){
            int parent = (pos-1)/2;
            int tempSwap = weightArr[pos];

            //swap
            weightArr[pos] = weightArr[parent];
            weightArr[parent] = tempSwap;
            pos = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int child; //to be assigned
        while ((weightArr[pos] > weightArr[(2*pos)+1] || weightArr[pos] > weightArr[(2*pos)+2]) && pos < size) {
            //determine smaller child to be swapped with
            if (weightArr[(2*pos)+1] > weightArr[(2*pos)+2]) {
                child = weightArr[(2*pos)+2];
            }else {
                child = weightArr[(2*pos)+1];
            }

            //swap
            int tempSwap = weightArr[pos];
            weightArr[pos] = weightArr[child];
            weightArr[child] = tempSwap;
            pos = child;
        }
    }
};

#endif