#include <iostream>
#include "../Linked Lists/linked_lists.h"

using namespace std;

class Stack
{
private:
    LinkedList linkedList = LinkedList();

public:
    Stack() {}

    void insert(int value)
    {
        linkedList.push(value);
    }

    int remove()
    {
        int result = linkedList.last();
        linkedList.pop();
        return result;
    }
};
