#include <iostream>
#include "tree_node.h"
#include "../Linked Lists/linked_lists.h"

using namespace std;

template <class T>
class Queue
{
private:
    LinkedList<T> linkedList = LinkedList<T>();

public:
    Queue() {}

    void enqueue(T value)
    {
        linkedList.push(value);
    }

    T dequeue()
    {
        T result = linkedList.first();
        linkedList.removeAt(0);
        return result;
    }
};

typedef TreeNode<int> *Node;

class BinarySearchTree
{
private:
    Node rootNode = NULL;
    int treeSize = 0;
    int height = 0, height_temp = 0;

    /// THE offset POINTER NEEDS TO BE A REFERENCE BECAUSE WE DO MODIFICATIONS WHICH MUST REFLECT GLOBALLY
    bool pushInternal(int value, Node &offset)
    {
        if (offset == NULL)
        {
            offset = new TreeNode(value);
            return true;
        }

        if (value <= (*offset).value)
        {
            // SEND TO LEFT
            height_temp++;
            return pushInternal(value, (*offset).left);
        }
        else
        {
            // SEND TO RIGHT
            height_temp++;
            return pushInternal(value, (*offset).right);
        }
    }

    int sumAllInternal(Node offset)
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

    void printAllInternal(Node offset)
    {
        if ((*offset).left != NULL)
        {
            cout << (*offset).value << "'s left: " << (*(*offset).left).value << endl;
        }
        if ((*offset).right != NULL)
        {
            cout << (*offset).value << "'s right: " << (*(*offset).right).value << endl;
        }

        cout << endl;

        if ((*offset).left != NULL)
        {
            // RECURSIVE CALL
            printAllInternal((*offset).left);
        }
        if ((*offset).right != NULL)
        {
            // RECURSIVE CALL
            printAllInternal((*offset).right);
        }
    }

    bool containsInternal(int value, Node offset)
    {
        if (offset == NULL)
        {
            return false;
        }

        int currentValue = (*offset).value;
        if (currentValue == value)
        {
            return true;
        }
        if (value < currentValue)
        {
            // RECURSIVE CALL
            return containsInternal(value, (*offset).left);
        }
        // RECURSIVE CALL
        return containsInternal(value, (*offset).right);

        // THIS STATEMENT DOESN'T CREATE BRANCHES ON THE CPU
        // return ((currentValue == value) + ((value < currentValue) * containsInternal(value, (*offset).left)) + ((value > currentValue) * containsInternal(value, (*offset).right)));
    }

    Node deleteElementInternal(int value, Node offset)
    {
        if ((*offset).value == value)
        {
            // RETURN THE SMALLEST ELEMENT IN THE RIGHT SUB-TREE
            Node smallestElement = getSmallestElement((*offset).right);
            if (smallestElement != NULL)
            {
                // SHIFT ALL THE RIGHT SUBTREE UPWARDS
                Node copyTemp = smallestElement;
                while (smallestElement != NULL)
                {
                    smallestElement = (*smallestElement).right;
                }

                return copyTemp;
            }

            // THERE IS NO CHILD ON THE RIGHT
            Node left = (*offset).left;

            // SHIFT ALL THE LEFT SUBTREE UPWARDS
            Node copyTemp = (*offset).left;
            while (copyTemp != NULL)
            {
                copyTemp = (*copyTemp).left;
            }

            return left;
        }
        if ((*offset).value > value)
        {
            (*offset).left = deleteElementInternal(value, (*offset).left);
        }
        if ((*offset).value < value)
        {
            (*offset).right = deleteElementInternal(value, (*offset).right);
        }

        // IF THIS NODE IS NOT THE NODE TO BE DELETED, RETURNS ITSELF
        return offset;
    }

    Node getSmallestElement(Node offset)
    {
        if (offset == NULL)
        {
            return NULL;
        }

        Node node = offset;
        while ((*node).left != NULL)
        {
            node = (*node).left;
        }

        return node;
    }

    Node searchNode(int value, Node offset)
    {
        if (offset == NULL)
        {
            return NULL;
        }

        int currentValue = (*offset).value;
        if (currentValue == value)
        {
            return offset;
        }
        if (value < currentValue)
        {
            // RECURSIVE CALL
            return searchNode(value, (*offset).left);
        }

        // RECURSIVE CALL
        return searchNode(value, (*offset).right);
    }

    Node parentOf(int value, Node offset)
    {
        if (offset == NULL)
        {
            return NULL;
        }

        Node leftChild = (*offset).left;
        Node rightChild = (*offset).right;

        if (leftChild == NULL && rightChild == NULL)
        {
            return NULL;
        }

        // IF THE SEARCHED VALUE IS EQUAL TO ONE OF THE CHILDREN'S VALUE, THIS NODE IS THE PARENT
        if ((leftChild != NULL && (*leftChild).value == value) || (rightChild != NULL && (*rightChild).value == value))
        {
            return offset;
        }

        Node continueFrom;
        // IF THE SEARCHED VALUE IS SMALLER THAN THIS NODE'S VALUE, CONTINUE SEARCHING FROM THE LEFT SUB-TREE
        if ((leftChild == NULL || value > (*offset).value) && rightChild != NULL)
        {
            continueFrom = rightChild;
        }

        // IF THE SEARCHED VALUE IS GREATER THAN THIS NODE'S VALUE, CONTINUE SEARCHING FROM THE RIGHT SUB-TREE
        else if ((rightChild == NULL || value < (*offset).value) && leftChild != NULL)
        {
            continueFrom = leftChild;
        }
        else
        {
            return NULL;
        }

        // RECURSIVE CALL
        return parentOf(value, continueFrom);
    }

    int power(int a, int b)
    {
        int result = 1;
        for (int i = 0; i < b; i++)
        {
            result *= a;
        }
        return result;
    }

    void drawInternal()
    {
        // LEVEL ORDER TRAVERSAL WITH QUEUE
        Queue<Node> queue = Queue<Node>();
        int arraySize = power(2, (height + 1));
        int *array = new int(arraySize);
        // cout << "arraySize: " << arraySize << endl;

        queue.enqueue(rootNode);
        Node offset;

        for (int i = 1; i < arraySize; i++)
        {
            offset = queue.dequeue();

            if (offset == NULL)
            {
                cout << "break";
                break;
            }

            if ((*offset).left != NULL)
            {
                queue.enqueue((*offset).left);
            }
            else
            {
                queue.enqueue(new TreeNode<int>(0));
            }
            if ((*offset).right != NULL)
            {
                queue.enqueue((*offset).right);
            }
            else
            {
                queue.enqueue(new TreeNode<int>(0));
            }

            array[i] = (*offset).value;

            // cout << array[i] << "  ";
        }

        for (int i = 1; i < arraySize; i *= 2)
        {
            int numberOfElements = (i * 2) - i;
            int numberOfSpaces = (i <= 2) ? (arraySize / (i + 1)) + (arraySize / i) : (arraySize / i * 2);

            for (int j = i; j < (i * 2); j++)
            {
                drawBlankSpace(numberOfSpaces);
                if (array[j] == 0)
                {
                    cout << "-";
                }
                else
                {
                    cout << array[j];
                }
            }

            cout << endl
                 << endl;
        }

        /* for (int i = 1; i < arraySize; i++)
        {
            cout << array[i] << "  ";
        } */

        return;
    }

    void drawBlankSpace(int a)
    {
        for (int k = 0; k < a; k++)
        {
            cout << " ";
        }
    }

public:
    BinarySearchTree(Node _rootNode = NULL)
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
        height_temp = 0;
        treeSize++;
        bool result = pushInternal(value, rootNode);
        if (height_temp > height)
        {
            height = height_temp;
        }
        return result;
    }

    int root()
    {
        return (*rootNode).value;
    }

    void printAll()
    {
        cout << "TREE SIZE: " << treeSize << endl;
        cout << "TREE HEIGHT: " << height << endl
             << endl;
        if (rootNode != NULL)
        {
            cout << "ROOT: " << (*rootNode).value << endl
                 << endl;
            printAllInternal(rootNode);
        }
        return;
    }

    bool contains(int value)
    {
        return containsInternal(value, rootNode);
    }

    bool deleteElement(int value)
    {
        if (!containsInternal(value, rootNode))
        {
            cout << "Element doesn't exist in the tree." << endl;
            return false;
        }

        deleteElementInternal(value, rootNode);
        treeSize--;
        return true;
    }

    void draw()
    {
        return drawInternal();
    }
};
