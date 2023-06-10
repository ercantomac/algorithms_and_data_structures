#include <iostream>
#include "my_node.h"

using namespace std;

class BinarySearchTree
{
private:
    MyNode *rootNode = NULL;

    /// THE offset POINTER NEEDS TO BE A REFERENCE BECAUSE WE DO MODIFICATIONS WHICH MUST REFLECT GLOBALLY
    bool pushInternal(int value, MyNode *&offset)
    {
        if (offset == NULL)
        {
            offset = new MyNode(value);
            return true;
        }

        if (value <= (*offset).value)
        {
            // SEND TO LEFT
            return pushInternal(value, (*offset).left);
        }
        else
        {
            // SEND TO RIGHT
            return pushInternal(value, (*offset).right);
        }
    }

    int sumAllInternal(MyNode *offset)
    {
        int leftSum = 0, rightSum = 0;

        if ((*offset).left != NULL)
        {
            leftSum = sumAllInternal((*offset).left);
        }

        if ((*offset).right != NULL)
        {
            rightSum = sumAllInternal((*offset).right);
        }

        return ((*offset).value + leftSum + rightSum);
    }

    void printAllInternal(MyNode *offset)
    {
        if (offset == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        cout << (*offset).value << endl;

        cout << (*offset).value << "'s left: ";
        if ((*offset).left == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << (*(*offset).left).value;
        }
        cout << endl;

        cout << (*offset).value << "'s right: ";
        if ((*offset).right == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << (*(*offset).right).value;
        }

        cout << endl
             << endl;

        if ((*offset).left != NULL)
        {
            printAllInternal((*offset).left);
        }

        if ((*offset).right != NULL)
        {
            printAllInternal((*offset).right);
        }
    }

    bool containsInternal(int value, MyNode *offset)
    {
        if (offset == NULL)
        {
            return false;
        }

        int currentValue = (*offset).value;
        return (currentValue == value ? true : containsInternal(value, (value < currentValue ? (*offset).left : (*offset).right)));
    }

public:
    BinarySearchTree(MyNode *_rootNode = NULL)
    {
        rootNode = _rootNode;
    }

    int sumAll()
    {
        if (rootNode == NULL)
        {
            return 0;
        }
        return sumAllInternal(rootNode);
    }

    bool push(int value)
    {
        return pushInternal(value, rootNode);
    }

    int root()
    {
        return (*rootNode).value;
    }

    void printAll()
    {
        printAllInternal(rootNode);
    }

    bool contains(int value)
    {
        return containsInternal(value, rootNode);
    }
};