#include <iostream>
#include "my_node.h"

using namespace std;

template <class U>
class LinkedList
{
private:
    MyNode<U> *headNode = NULL;

public:
    LinkedList() {}

    /* void addNewNode()
    {
        MyNode *node = &headNode;
        while (true)
        {
            MyNode *temp = (*node).next;
            if (temp == NULL)
            {
                MyNode *newNode = new MyNode(((*node).value + 1));
                (*node).next = newNode;
                break;
            }
            else
            {
                node = (*node).next;
            }
        }
    } */

    int getNodeSize()
    {
        if (headNode == NULL)
        {
            return 0;
        }
        MyNode<U> *head = headNode;
        int cnt = 1;
        while ((*head).next != NULL)
        {
            cnt++;
            head = ((*head).next);
        }
        return cnt;
    }

    bool insert(int index, U value)
    {
        MyNode<U> *node = new MyNode(value);
        int nodeSize = getNodeSize();
        if (index > nodeSize || index < 0)
        {
            // index = nodeSize;
            return false;
        }

        // IF index == nodeSize, IT ADDS THE NEW NODE TO THE END (SAME AS addNewNode())

        /*if (index == 0)
        {
            // WE DON'T ACTUALLY INSERT THE NODE TO THE START, WE INSERT IT TO OFFSET [1],
            // THEN WE SWAP THE VALUES OF TWO NODES, CREATING THE ILLUSION OF INSERTING IT TO THE START :))
            // (WILL POTENTIALLY CAUSE ERRORS WHEN DOING DELETION)
            (*node).next = headNode.next;
            headNode.next = node;

            // SWAP THE VALUES
            int temp = (*node).value;
            (*node).value = headNode.value;
            headNode.value = temp;
        }*/
        if (index == 0)
        {
            (*node).next = headNode;
            headNode = node;

            return true;
        }
        MyNode<U> *offset = headNode;
        for (int i = 0; i < index; i++)
        {
            if (i == (index - 1))
            {
                (*node).next = (*offset).next;
                (*offset).next = node;
            }
            else
            {
                offset = (*offset).next;
            }
        }
        return true;
    }

    bool removeAt(int index)
    {
        int nodeSize = getNodeSize();
        if (nodeSize == 0 || index >= nodeSize || index < 0)
        {
            return false;
        }
        if (index == 0)
        {
            MyNode<U> *newFirst = (*headNode).next;

            //MyNode<U> *temp = headNode;
            //delete temp; // I AM DOING THIS TO DEALLOCATE THE MEMORY OF THE REMOVED NODE, BUT I AM NOT SURE IF IT WORKS

            headNode = newFirst;

            return true;
        }
        /* if (index >= nodeSize)
        {
            index = nodeSize - 1;
        } */

        MyNode<U> *offset = headNode;
        for (int i = 0; i < index; i++)
        {
            if (i == (index - 1))
            {
                // GETTING THE ADDRESS OF THE NODE WHICH WE WILL CONNECT TO WHERE THE REMOVED NODE WAS
                MyNode<U> *successorNode = (*(*offset).next).next;

                MyNode<U> *temp = (*offset).next; // ADDRESS OF THE NODE TO BE REMOVED
                delete temp;                      // I AM DOING THIS TO DEALLOCATE THE MEMORY OF THE REMOVED NODE, BUT I AM NOT SURE IF IT WORKS

                (*offset).next = successorNode;
            }
            else
            {
                offset = (*offset).next;
            }
        }
        return true;
    }

    bool pop()
    {
        return removeAt(getNodeSize() - 1);
    }

    bool push(U value)
    {
        return insert(getNodeSize(), value);
    }

    U get(int index)
    {
        int nodeSize = getNodeSize();
        if (nodeSize == 0 || index >= nodeSize || index < 0)
        {
            return NULL;
        }
        /* if (index >= nodeSize)
        {
            index = nodeSize - 1;
        } */

        MyNode<U> *offset = headNode;
        for (int i = 0; i < index; i++)
        {
            offset = (*offset).next;
        }
        return (*offset).value;
    }

    int indexOf(U value)
    {
        int nodeSize = getNodeSize();
        MyNode<U> *offset = headNode;

        for (int i = 0; i < nodeSize - 1; i++)
        {
            if (value == (*offset).value)
            {
                return i;
            }
            offset = (*offset).next;
        }

        return -1;
    }

    bool contains(U value)
    {
        int nodeSize = getNodeSize();
        MyNode<U> *offset = headNode;

        for (int i = 0; i < nodeSize - 1; i++)
        {
            if (value == (*offset).value)
            {
                return true;
            }
            offset = (*offset).next;
        }

        return false;
    }

    U last()
    {
        return get((getNodeSize() - 1));
    }

    U first()
    {
        if (headNode == NULL)
        {
            return NULL;
        }
        return (*headNode).value;
        // return get(0);
    }
};