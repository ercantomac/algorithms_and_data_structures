#include <iostream>

using namespace std;

class MyNode
{
public:
    int index;
    MyNode *next;

    MyNode(int _index, MyNode *_next = NULL)
    {
        index = _index;
        next = _next;
    }
};

class LinkedList
{
private:
    MyNode nodeInstance_0 = MyNode(0);

public:
    LinkedList(int size)
    {
        if (size > 1)
        {
            for (int i = 0; i < size - 1; i++)
            {
                addNewNode();
            }
        }
    }

    void addNewNode()
    {
        MyNode *node = &nodeInstance_0;
        while (true)
        {
            MyNode *temp = (*node).next;
            if (temp == NULL)
            {
                MyNode *newNode = new MyNode(((*node).index + 1));
                (*node).next = newNode;
                break;
            }
            else
            {
                node = (*node).next;
            }
        }
    }

    int getNodeSize()
    {
        MyNode head = nodeInstance_0;
        int cnt = 1;
        while (head.next != NULL)
        {
            cnt++;
            head = *(head.next);
        }
        return cnt;
    }

    void insert(int index, MyNode *node)
    {
        int nodeSize = getNodeSize();
        if (index > nodeSize)
        {
            index = nodeSize;
        }

        // IF index == nodeSize, IT ADDS THE NEW NODE TO THE END (SAME AS addNewNode())
        if (index == 0)
        {
            // WE DON'T ACTUALLY INSERT THE NODE TO THE START, WE INSERT IT TO OFFSET [1],
            // THEN WE SWAP THE VALUES OF TWO NODES, CREATING THE ILLUSION OF INSERTING IT TO THE START :))
            // (WILL POTENTIALLY CAUSE ERRORS WHEN DOING DELETION)
            (*node).next = nodeInstance_0.next;
            nodeInstance_0.next = node;

            // SWAP THE VALUES
            int temp = (*node).index;
            (*node).index = nodeInstance_0.index;
            nodeInstance_0.index = temp;
        }
        else
        {
            MyNode *offset = &nodeInstance_0;
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
        }
    }

    void remove(int index)
    {
        int nodeSize = getNodeSize();
        if (index >= nodeSize)
        {
            index = nodeSize - 1;
        }

        MyNode *offset = &nodeInstance_0;
        for (int i = 0; i < index; i++)
        {
            if (i == (index - 1))
            {
                // GETTING THE ADDRESS OF THE NODE WHICH WE WILL CONNECT TO WHERE THE REMOVED NODE WAS
                MyNode *successorNode = (*(*offset).next).next;

                MyNode *temp = (*offset).next; // ADDRESS OF THE NODE TO BE REMOVED
                delete temp;

                (*offset).next = successorNode;
            }
            else
            {
                offset = (*offset).next;
            }
        }
    }

    void pop()
    {
        remove(getNodeSize() - 1);
    }

    void push(MyNode *node)
    {
        insert(getNodeSize(), node);
    }

    MyNode get(int index)
    {
        int nodeSize = getNodeSize();
        if (index >= nodeSize)
        {
            index = nodeSize - 1;
        }

        MyNode *offset = &nodeInstance_0;
        for (int i = 0; i < index; i++)
        {
            offset = (*offset).next;
        }
        return *offset;
    }

    int indexOf(int value)
    {
        int nodeSize = getNodeSize();
        MyNode *offset = &nodeInstance_0;

        for (int i = 0; i < nodeSize - 1; i++)
        {
            if (value == (*offset).index)
            {
                return i;
            }
            offset = (*offset).next;
        }

        return -1;
    }

    bool contains(int value)
    {
        int nodeSize = getNodeSize();
        MyNode *offset = &nodeInstance_0;

        for (int i = 0; i < nodeSize - 1; i++)
        {
            if (value == (*offset).index)
            {
                return true;
            }
            offset = (*offset).next;
        }

        return false;
    }
};

int main()
{
    // CREATE THE INSTANCE
    LinkedList myLinkedList = LinkedList(43);
    int nodeSize = myLinkedList.getNodeSize();
    cout << "CREATE THE INSTANCE" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Last item's value: " << myLinkedList.get((nodeSize - 1)).index << endl
         << endl;

    // INSERT NEW NODE TO THE END
    // myLinkedList.addNewNode();
    myLinkedList.push(new MyNode(444));
    nodeSize = myLinkedList.getNodeSize();
    cout << "INSERT NEW NODE TO THE END" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Last item's value: " << myLinkedList.get((nodeSize - 1)).index << endl
         << endl;

    // INSERT NEW NODE TO THE START
    myLinkedList.insert(0, new MyNode(225));
    nodeSize = myLinkedList.getNodeSize();
    cout << "INSERT NEW NODE TO THE START" << endl;
    cout << "List length: " << nodeSize << endl;
    cout << "Second item's (previously first) value: " << myLinkedList.get(1).index << endl;
    cout << "New first item's value: " << myLinkedList.get(0).index << endl
         << endl;

    // REMOVE NODE AT THE OFFSET [5]
    nodeSize = myLinkedList.getNodeSize();
    cout << "REMOVE NODE AT THE OFFSET [5]" << endl;
    cout << "List length before deletion: " << nodeSize << endl;
    cout << "4th item's value before deletion: " << myLinkedList.get(4).index << endl;
    cout << "5th item's value before deletion: " << myLinkedList.get(5).index << endl;
    cout << "6th item's value before deletion: " << myLinkedList.get(6).index << endl;

    myLinkedList.remove(5);
    nodeSize = myLinkedList.getNodeSize();
    cout << "List length after deletion: " << nodeSize << endl;
    cout << "4th item's value after deletion: " << myLinkedList.get(4).index << endl;
    cout << "5th item's value after deletion: " << myLinkedList.get(5).index << endl;
    cout << "6th item's value after deletion: " << myLinkedList.get(6).index << endl
         << endl;

    // REMOVE THE LAST NODE
    nodeSize = myLinkedList.getNodeSize();
    cout << "REMOVE THE LAST NODE" << endl;
    cout << "List length before deletion: " << nodeSize << endl;
    cout << "Last item's value before deletion: " << myLinkedList.get((nodeSize - 1)).index << endl;

    myLinkedList.pop();
    nodeSize = myLinkedList.getNodeSize();
    cout << "List length after deletion: " << nodeSize << endl;
    cout << "Last item's value after deletion: " << myLinkedList.get((nodeSize - 1)).index << endl
         << endl;

    // INDEX OF THE NODE WHOSE VALUE IS '31'
    int indexOf31 = myLinkedList.indexOf(31);
    cout << "INDEX OF THE NODE WHOSE VALUE IS '31'" << endl;
    cout << indexOf31 << endl;
    cout << "Checking if it's correct: " << myLinkedList.get(indexOf31).index << endl
         << endl;

    // CHECK IF THE LIST CONTAINS A CERTAIN ELEMENT
    cout << "CHECK IF THE LIST CONTAINS A CERTAIN ELEMENT" << endl;
    cout << "CONTAINS '31': " << (myLinkedList.contains(31) ? "TRUE" : "FALSE") << endl;
    cout << "CONTAINS '75': " << (myLinkedList.contains(75) ? "TRUE" : "FALSE") << endl
         << endl;

    return 0;
}
