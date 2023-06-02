#include <iostream>
//#include "my_node.h"
#include "linked_lists.h"

using namespace std;

int main()
{
    // CREATE THE INSTANCE
    LinkedList myLinkedList = LinkedList();
    for (int i = 0; i < 43; i++)
    {
        myLinkedList.push(i);
    }
    int nodeSize = myLinkedList.getNodeSize();
    cout << "CREATE THE INSTANCE" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Last item's value: " << myLinkedList.last() << endl
         << endl;

    // INSERT NEW NODE TO THE END
    myLinkedList.push(444);
    nodeSize = myLinkedList.getNodeSize();
    cout << "INSERT NEW ELEMENT (444) TO THE END" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Last item's value: " << myLinkedList.last() << endl
         << endl;

    // INSERT NEW NODE TO THE START
    myLinkedList.insert(0, 225);
    nodeSize = myLinkedList.getNodeSize();
    cout << "INSERT NEW ELEMENT (225) TO THE START" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Second item's (previously first) value: " << myLinkedList.get(1) << endl;
    cout << "New first item's value: " << myLinkedList.first() << endl
         << endl;

    // REMOVE THE FIRST NODE
    nodeSize = myLinkedList.getNodeSize();
    cout << "REMOVE THE FIRST NODE" << endl;
    cout << "List length before deletion: " << nodeSize << endl;
    cout << "First item's value before deletion: " << myLinkedList.first() << endl;

    myLinkedList.removeAt(0);
    nodeSize = myLinkedList.getNodeSize();
    cout << "List length after deletion: " << nodeSize << endl;
    cout << "First item's value after deletion: " << myLinkedList.first() << endl
         << endl;

    // REMOVE NODE AT THE OFFSET [5]
    nodeSize = myLinkedList.getNodeSize();
    cout << "REMOVE ELEMENT AT THE OFFSET [5]" << endl;
    cout << "List length before deletion: " << nodeSize << endl;
    cout << "4th item's value before deletion: " << myLinkedList.get(4) << endl;
    cout << "5th item's value before deletion: " << myLinkedList.get(5) << endl;
    cout << "6th item's value before deletion: " << myLinkedList.get(6) << endl;

    myLinkedList.removeAt(5);
    nodeSize = myLinkedList.getNodeSize();
    cout << "List length after deletion: " << nodeSize << endl;
    cout << "4th item's value after deletion: " << myLinkedList.get(4) << endl;
    cout << "5th item's value after deletion: " << myLinkedList.get(5) << endl;
    cout << "6th item's value after deletion: " << myLinkedList.get(6) << endl
         << endl;

    // REMOVE THE LAST NODE
    nodeSize = myLinkedList.getNodeSize();
    cout << "REMOVE THE LAST ELEMENT" << endl;
    cout << "List length before deletion: " << nodeSize << endl;
    cout << "Last item's value before deletion: " << myLinkedList.last() << endl;

    myLinkedList.pop();
    nodeSize = myLinkedList.getNodeSize();
    cout << "List length after deletion: " << nodeSize << endl;
    cout << "Last item's value after deletion: " << myLinkedList.last() << endl
         << endl;

    // INDEX OF THE NODE WHOSE VALUE IS '31'
    int indexOf31 = myLinkedList.indexOf(31);
    cout << "INDEX OF THE ELEMENT WHOSE VALUE IS '31'" << endl;
    cout << indexOf31 << endl;
    cout << "Checking if it's correct: " << myLinkedList.get(indexOf31) << endl
         << endl;

    // CHECK IF THE LIST CONTAINS A CERTAIN ELEMENT
    cout << "CHECK IF THE LIST CONTAINS A CERTAIN ELEMENT" << endl;
    cout << "CONTAINS '31': " << (myLinkedList.contains(31) ? "TRUE" : "FALSE") << endl;
    cout << "CONTAINS '75': " << (myLinkedList.contains(75) ? "TRUE" : "FALSE") << endl
         << endl;

    return 0;
}
