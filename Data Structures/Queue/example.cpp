#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue queue = Queue();

    cout << "enqueue 1" << endl;
    queue.enqueue(1);
    cout << "enqueue 2" << endl;
    queue.enqueue(2);
    cout << "enqueue 3" << endl;
    queue.enqueue(3);
    cout << "enqueue 4" << endl;
    queue.enqueue(4);

    cout << "dequeue: " << queue.dequeue() << endl;
    cout << "dequeue: " << queue.dequeue() << endl;

    cout << "enqueue 5" << endl;
    queue.enqueue(5);
    cout << "enqueue 6" << endl;
    queue.enqueue(6);

    cout << "dequeue: " << queue.dequeue() << endl;
    cout << "dequeue: " << queue.dequeue() << endl;
    cout << "dequeue: " << queue.dequeue() << endl;
    cout << "dequeue: " << queue.dequeue() << endl;

    cout << "dequeue: " << queue.dequeue() << endl;
    cout << "dequeue: " << queue.dequeue() << endl;
    return 0;
}