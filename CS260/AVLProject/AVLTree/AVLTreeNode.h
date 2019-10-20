#ifndef AVLTREENODE_H
#define AVLTREENODE_H
#include "TreeNode.h"

template<class T>
class AVLTreeNode : public TreeNode<T> //inherits from the Tree node class and adds the height componant
{
public:
    int height;
    AVLTreeNode<T>(T theElement);
};

template<class T>
AVLTreeNode<T>::AVLTreeNode(T theElement) : TreeNode<T>(theElement) //calls the Treenode constuctor and then sets the height to 0
{
    height = 0;
}

#endif // AVLTREENODE_H
