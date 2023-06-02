#include <iostream>
#include "../Linked Lists/linked_lists.h"

using namespace std;

class Queue
{
private:
    LinkedList linkedList = LinkedList();

public:
    Queue() {}

    void enqueue(int value)
    {
        linkedList.push(value);
    }

    int dequeue()
    {
        int result = linkedList.first();
        linkedList.removeAt(0);
        return result;
    }
};
