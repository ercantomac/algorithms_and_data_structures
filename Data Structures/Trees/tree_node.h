#include <iostream>

using namespace std;

template <typename X>
class TreeNode
{
public:
    X value;
    TreeNode *left, *right;

    TreeNode(X _value, TreeNode *_left = NULL, TreeNode *_right = NULL)
    {
        value = _value;
        left = _left;
        right = _right;
    }
};