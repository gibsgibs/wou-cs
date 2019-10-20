#ifndef ITERATOR_H
#define ITERATOR_H
#include "TreeNode.h"
#include <vector>
using namespace std;

/*This file was written by Stacia Fry*/

template<class T>
class Iterator : public iterator<forward_iterator_tag, T>
{
public:
    vector<T> v;
    Iterator(TreeNode<T>* p)
    {
        if(p == NULL)
        {
            current = -1;
        }
        else
        {
            treeToVector(p);
            current = 0;
        }
    }
    Iterator operator++()
    {
        current++;
        if(current == v.size())
        {
            current = -1;
            return *this;
        }
    }
    T &operator*()
    {
        return v[current];
    }
    bool operator== (const Iterator<T> &iterator) const
    {
        return current == iterator.current;
    }
    bool operator!=(const Iterator<T> &iterator) const
    {
        return current != iterator.current;
    }
private:
    int current;
    void treeToVector(TreeNode<T>* p)
    {
        if(p != NULL)
        {
            treeToVector(p->left);
            v.push_back(p->element);
            treeToVector(p->right);
        }
    }
};

#endif // ITERATOR_H
