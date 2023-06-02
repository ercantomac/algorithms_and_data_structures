#include <iostream>

using namespace std;

class MyNode
{
public:
    int value;
    MyNode *next;

    MyNode(int _value, MyNode *_next = NULL)
    {
        value = _value;
        next = _next;
    }
};