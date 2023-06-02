#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack stack = Stack();

    cout << "insert 1" << endl;
    stack.insert(1);
    cout << "insert 2" << endl;
    stack.insert(2);
    cout << "insert 3" << endl;
    stack.insert(3);
    cout << "insert 4" << endl;
    stack.insert(4);

    cout << "remove: " << stack.remove() << endl;
    cout << "remove: " << stack.remove() << endl;

    cout << "insert 5" << endl;
    stack.insert(5);
    cout << "insert 6" << endl;
    stack.insert(6);

    cout << "remove: " << stack.remove() << endl;
    cout << "remove: " << stack.remove() << endl;
    cout << "remove: " << stack.remove() << endl;
    cout << "remove: " << stack.remove() << endl;

    cout << "remove: " << stack.remove() << endl;
    cout << "remove: " << stack.remove() << endl;
    return 0;
}
