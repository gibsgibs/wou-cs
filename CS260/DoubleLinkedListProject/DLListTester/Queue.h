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
     * @brief enqueue
     * @param theElement
     */
    void enqueue(T theElement)
    {
        list.add(theElement);
    }

    /**
     * @brief dequeue
     * @return
     */
    T dequeue()
    {
        return list.removeAt(0);
    }

    /**
     * @brief getSize
     * @return
     */
    int getSize() const
    {
        return list.getSize();
    }

    /**
     * @brief front
     * @return
     */
    T front()
    {
        return list.get(0);
    }

    /**
     * @brief back
     * @return
     */
    T back()
    {
        return list.get(list.getSize() - 1);
    }
};

#endif // QUEUE_H
