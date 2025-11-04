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
        if (size == 64) { //edgecase
            cout<<"Cannot push, array full."<<endl;
            return;
        }

        data[size] = idx;
        size++;
        upheap(size-1,weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0){ //edgecase
            cout<<"Cannot pop, array empty."<<endl;
            return -1;
        }

        int ogRoot = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0,weightArr);
        return ogRoot;
    }

    void upheap(int pos, int weightArr[]) {
        if (size <=1) { //edgecase
            cout << "Nothing to upheap." <<endl;
            return;
        }

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
        if (size <=1) { //edgecase
            cout << "Nothing to downheap." <<endl;
            return;
        }

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