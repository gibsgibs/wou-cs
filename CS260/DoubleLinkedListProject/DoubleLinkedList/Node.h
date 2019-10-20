#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T element; //the data the node is holding
    Node* next; //a pointer to the next node
    Node* prev; //a pointer to the previous node

    /**
     * @brief Node - the no arg constuctor that creates a node
     */
    Node()
    {
        next = NULL; //sets the next pointer to null
        prev = NULL; //sets the previous pointer to null
    }

    /**
     * @brief Node - the single arg constuctor that creates a node holding the given element(data)
     * @param theElement - the data being passed in
     */
    Node(T theElement)
    {
        this->element = theElement; //sets the element to the given element
        next = NULL; //sets the next pointer to null
        prev = NULL; //sets the previous pointer to null
    }
};

#endif // NODE_H
