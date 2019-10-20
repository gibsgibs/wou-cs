#ifndef QUEUE_H
#define QUEUE_H
#include "DLList.h"

template<class T>
class Queue
{
private:
    DLList<T> list;

public:
    /**
     * @brief enqueue - adds a node with thegiven element to the end
     *                  of the queue by using the add() function.
     * @param theElement - the element of node being added
     */
    void enqueue(T theElement)
    {
        list.add(theElement);
    }

    /**
     * @brief dequeue - removes the node at the from of the queue, using
     *                  the removeAt(index) function.
     * @return - returns the element of the removed node.
     */
    T dequeue()
    {
        return list.removeAt(0);
    }

    /**
     * @brief getSize - literally gets the size of the queue using the
     *                  getSize() function.
     * @return - returns the size of the queue
     */
    int getSize() const
    {
        return list.getSize();
    }

    /**
     * @brief front - gets the element of the first node in the queue.
     * @return - returns the element of the first item in the queue.
     */
    T front()
    {
        return list.get(0);
    }

    /**
     * @brief back - gets the element last node in the queue.
     * @return - returns the element of the last node in the queue.
     */
    T back()
    {
        return list.get(list.getSize() - 1);
    }
};

#endif // QUEUE_H
