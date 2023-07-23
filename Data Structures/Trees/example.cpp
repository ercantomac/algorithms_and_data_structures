#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BinarySearchTree myTree = BinarySearchTree();
    myTree.push(5);
    myTree.push(1);
    myTree.push(3);
    myTree.push(2);
    myTree.push(7);
    myTree.push(8);
    myTree.push(4);
    myTree.push(6);

    myTree.printAll();

    cout << endl
         << "Sum of all the elements in the tree: " << myTree.sumAll() << endl
         << endl;

    cout << "Does tree contain the number 0? " << (myTree.contains(0) ? "TRUE" : "FALSE") << endl;
    cout << "Does tree contain the number 3? " << (myTree.contains(3) ? "TRUE" : "FALSE") << endl;
    cout << "Does tree contain the number 8? " << (myTree.contains(8) ? "TRUE" : "FALSE") << endl;
    cout << "Does tree contain the number 10? " << (myTree.contains(10) ? "TRUE" : "FALSE") << endl;
    cout << "Does tree contain the number -6? " << (myTree.contains(-6) ? "TRUE" : "FALSE") << endl;
    cout << "Does tree contain the number 4? " << (myTree.contains(4) ? "TRUE" : "FALSE") << endl
         << endl;

    myTree.draw();
    cout << endl;

    bool a = myTree.deleteElement(4);
    cout << "Delete 4: " << a << endl
         << endl;
    cout << "Does tree contain the number 4? " << (myTree.contains(4) ? "TRUE" : "FALSE") << endl
         << endl;
    myTree.printAll();

    return 0;
}