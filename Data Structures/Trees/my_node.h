#include <iostream>

using namespace std;

class MyNode
{
public:
    int value;
    MyNode *left, *right;

    MyNode(int _value, MyNode *_left = NULL, MyNode *_right = NULL)
    {
        value = _value;
        left = _left;
        right = _right;
    }
};