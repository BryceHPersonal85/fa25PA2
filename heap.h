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
        if (size >= 64) { //edgecase
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
        // TODO: swap child upward while smaller than parent

        int child = pos;
        while (child > 0) {
            int parent = (child - 1) / 2; //formula for parent
            if (weightArr[data[parent]] <= weightArr[data[child]]) {
                break; //already minheap
            }

            //swap
            int temp = data[parent];
            data[parent] = data[child];
            data[child] = temp;
            child = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child

        if (pos < 0 || pos >= size) { //edgecase
            return;
        }

        int parent = pos;
        while (((2 * parent) + 1) < size) {
            int childL = (2 * parent) + 1; //child formula (haha like the liquid)
            int childR = (2 * parent) + 2; //child formula

            int smallest;

            if ((weightArr[data[childR]] < weightArr[data[childL]]) && (childR < size)){
                smallest = childR; //right smaller
            }else {
                smallest = childL; //left smaller
            }

            if (weightArr[data[parent]] <= weightArr[data[smallest]]) {
                break; //already minheap
            }

            //swap
            int temp = data[parent];
            data[parent] = data[smallest];
            data[smallest] = temp;
            parent = smallest;
        }
    }
};

#endif