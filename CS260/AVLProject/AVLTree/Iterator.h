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
    /**
     * @brief Iterator - one arg constuctor that creates an iterator at the given tree node
     * @param p - the given tree node
     */
    Iterator(TreeNode<T>* p)
    {
        if(p == NULL)           //if the node is null
        {
            current = -1;       //set the current to -1
        }
        else
        {
            treeToVector(p);    //turn the tree into a vector
            current = 0;        //set the current to 0
        }
    }
    /**
     * @brief operator ++ - overload the ++ operator so we can go from node to node
     * @return - returns a pointer to the iterator
     */
    Iterator operator++()
    {
        current++;                                      //increment the current
        if(current == static_cast<int>(v.size()))       //if the current is equal to the size of the vector
        {
            current = -1;                               //current gets set equal to -1
        }
        return *this;                                   //returns a pointer to the iterator
    }
    /**
     * @brief operator * - overlaods the dereferance operator so we can return the node the iterator is pointing at
     * @return - returns the node the iterator is pointing at
     */
    T &operator*()
    {
        return v[current]; //return the element in the vector
    }
    /**
     * @brief operator == - overloads the equal to operator so we can compare the nodes
     * @param other - the other iterator we are using for comparison
     * @return - return true or false based on the result of the comparison
     */
    bool operator== (const Iterator<T> &other) const
    {
        return current == other.current; //true if the node at the iterator is equal to the node at the other iterator
    }
    /**
     * @brief operator != - overloads the not equal to operator so we can compare the nodes
     * @param other - the other iterator we are using for comparison
     * @return - returns true or false based on the result of the comparsion
     */
    bool operator!=(const Iterator<T> &other) const
    {
        return current != other.current; //true if the node at the iterator is not equal to the node at the other iterator
    }

private:
    int current; //a private int member variable
    /**
     * @brief treeToVector - turns the tree into a vector recursivly
     * @param p - takes in a pointer to a node
     */
    void treeToVector(TreeNode<T>* p)
    {
        if(p != NULL)                   //as long as p is not a NULL poiter
        {
            treeToVector(p->left);      //recursivly calls the function on the left child
            v.push_back(p->element);    //adds the element to the vector
            treeToVector(p->right);     //recursivly calls the function on the right child
        }
    }
};

#endif // ITERATOR_H
