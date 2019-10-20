#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

template<class T>
class TreeNode
{
public:
    T element; //Element contained in the node
    TreeNode<T>* left; //Pointer to the left child
    TreeNode<T>* right; //Pointer to the right child
    int height; //height of the node

    TreeNode() //No-arg constuctor
    {
        left = NULL;
        right = NULL;
        height = 0;
    }

    TreeNode(T theElement) //Constructor
    {
        this->element = theElement;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

#endif // TREENODE_H
