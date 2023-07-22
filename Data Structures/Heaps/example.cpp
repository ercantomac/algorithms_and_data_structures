#include <iostream>
#include "max_heap.h"
#include "min_heap.h"

using namespace std;

int main()
{
    cout << "Max heap:" << endl;
    MaxHeap maxHeap = MaxHeap();
    maxHeap.insert(10);
    maxHeap.insert(7);
    maxHeap.insert(5);
    maxHeap.insert(25);
    maxHeap.printAll();
    cout << endl
         << "deleteMax()" << endl;
    maxHeap.deleteMax();
    maxHeap.printAll();

    cout << endl
         << endl;

    cout << "Min heap:" << endl;
    MinHeap minHeap = MinHeap();
    minHeap.insert(10);
    minHeap.insert(7);
    minHeap.insert(5);
    minHeap.insert(25);
    minHeap.printAll();
    cout << endl
         << "deleteMin()" << endl;
    minHeap.deleteMin();
    minHeap.printAll();
}