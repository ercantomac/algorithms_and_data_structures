#include <iostream>

using namespace std;

template <class V>
class MyNode
{
public:
    V value;
    MyNode *next;

    MyNode(V _value, MyNode *_next = NULL)
    {
        value = _value;
        next = _next;
    }
};