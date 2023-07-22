#include <iostream>

using namespace std;

class MinHeap
{

private:
    int *heap = new int(4);
    int heapSize = 4;
    int heapLoad = 0;

    void checkHeapLoad()
    {
        if (heapLoad >= (heapSize - (heapSize / 4)))
        {
            expandHeap();
        }
    }

    void expandHeap()
    {
        int *newHeap = new int(heapSize * 2);
        for (int i = 1; i <= heapLoad; i++)
        {
            newHeap[i] = heap[i];
        }
        heapSize *= 2;

        heap = newHeap;
    }

    void heapifyUp()
    {
        for (int i = heapLoad; i > 0; i--)
        {
            int parent = parentOf(i);
            if (parent != NULL && heap[i] < parent)
            {
                swap(i, indexOf(parent));
            }
        }
    }

    void heapifyDown()
    {
        for (int i = 1; i <= heapLoad; i++)
        {
            int leftChild = leftChildOf(i);
            int rightChild = rightChildOf(i);
            int childToSwap = min(leftChild, rightChild);

            if (childToSwap != NULL && heap[i] > childToSwap)
            {
                swap(i, indexOf(childToSwap));
            }
        }
    }

    void swap(int a, int b)
    {
        if (a < 1 || b < 1 || a > heapLoad || b > heapLoad)
        {
            return;
        }

        int temp = at(a);
        heap[a] = at(b);
        heap[b] = temp;
    }

    int min(int a, int b)
    {
        if (a == NULL)
        {
            return b;
        }
        if (b == NULL)
        {
            return a;
        }
        return (a <= b) ? a : b;
    }

    int leftChildOf(int index)
    {
        return at(index * 2);
    }

    int rightChildOf(int index)
    {
        return at((index * 2) + 1);
    }

    int parentOf(int index)
    {
        if ((index > heapLoad) || (index <= 1))
        {
            return NULL;
        }
        return at((index % 2 == 0) ? (index / 2) : ((index - 1) / 2));
    }

    int at(int index)
    {
        if ((index > heapLoad) || (index < 1))
        {
            return NULL;
        }
        return heap[index];
    }

    int indexOf(int element)
    {
        for (int i = 1; i <= heapLoad; i++)
        {
            if (at(i) == element)
            {
                return i;
            }
        }
        return NULL;
    }

    bool contains(int value)
    {
        for (int i = 1; i <= heapLoad; i++)
        {
            if (heap[i] == value)
            {
                return true;
            }
        }
        return false;
    }

public:
    MinHeap() {}

    void insert(int element)
    {
        if (contains(element))
        {
            cout << "Element already exists in the heap." << endl;
            return;
        }

        // ADD THE NEW ELEMENT AT THE END
        heap[heapLoad + 1] = element;
        heapLoad++;
        // RESTORE THE ORDER PROPERTY, STARTING FROM BOTTOM
        heapifyUp();
        // CHECK IF THE ARRAY NEEDS TO BE EXPANDED
        checkHeapLoad();
    }

    void deleteMin()
    {
        if (heapLoad == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        // MOVE THE LAST ELEMENT TO THE START
        heap[1] = heap[heapLoad];
        heap[heapLoad] = NULL;
        heapLoad--;
        // RESTORE THE ORDER PROPERTY, STARTING FROM TOP
        heapifyDown();
    }

    void printAll()
    {
        cout << "ROOT: " << heap[1] << endl
             << endl;
        for (int i = 1; i <= heapLoad; i++)
        {
            /* if (indexOf(leftChildOf(i)) <= heapLoad || indexOf(rightChildOf(i)) <= heapLoad)
            {
                cout << heap[i] << endl
                     << endl;
            } */

            if (indexOf(leftChildOf(i)) <= heapLoad)
            {
                cout << heap[i] << "'s left: " << leftChildOf(i) << endl;
            }
            if (indexOf(rightChildOf(i)) <= heapLoad)
            {
                cout << heap[i] << "'s right: " << rightChildOf(i) << endl;
            }

            cout << endl;
        }
    }
};