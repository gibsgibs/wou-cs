#ifndef DLLISTITERATOR_H
#define DLLISTITERATOR_H
#include "Node.h"

template<class T>
class DLList;

template <class T>
class DLListIterator
{
    friend class DLList<T>;

private:
    Node<T>* nodeIterator = NULL;
public:
    /**
     * @brief DLListIterator
     * @param position
     */
    DLListIterator(Node<T>* const position)
    {
        nodeIterator = position;
    }

    /**
     * @brief operator ++
     * @return
     */
    DLListIterator operator++()
    {
        nodeIterator = nodeIterator->next;
        return *this;
    }

    /**
     * @brief operator --
     * @return
     */
    DLListIterator operator--()
    {
        nodeIterator = nodeIterator->prev;
        return *this;
    }

    /**
     * @brief operator *
     * @return
     */
    T operator*()
    {
        return nodeIterator->element;
    }

    /**
     * @brief operator ==
     * @param other
     * @return
     */
    bool operator==(const DLListIterator<T>& other) const
    {
        if(nodeIterator == other.nodeIterator)
            return true;
        else
            return false;
    }

    /**
     * @brief operator !=
     * @param other
     * @return
     */
    bool operator!=(const DLListIterator<T>& other) const
    {
        if(nodeIterator != other.nodeIterator)
            return true;
        else
            return false;
    }

};

#endif // DLLISTITERATOR_H
