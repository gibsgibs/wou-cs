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
    DLListIterator(Node<T>* const position)
    {
        nodeIterator = position;
    }

    /**
     * @brief operator ++ - operator overload so we can increment the
     *                      iterator.
     * @return - returns the incremented iterator.
     */
    DLListIterator operator++()
    {
        nodeIterator = nodeIterator->next;
        return *this;
    }

    /**
     * @brief operator -- - overloaded decrement operator so we can
     *                      decrement the iterator.
     * @return - the decremented iterator.
     */
    DLListIterator operator--()
    {
        nodeIterator = nodeIterator->prev;
        return *this;
    }

    /**
     * @brief operator * - overloaded dereferance operator so we can
     *                     dereferance the iterator.
     * @return - the data in the node the iterator is pointing at.
     */
    T operator*()
    {
        return nodeIterator->element;
    }

    /**
     * @brief operator == - overloaded equals operator so we can compare
     *                      iterators.
     * @param other - the other iterator being compared.
     * @return - returns true or false depending on the outcome of the
     *           comparison.
     */
    bool operator==(const DLListIterator<T>& other) const
    {
        if(nodeIterator == other.nodeIterator)
            return true;
        else
            return false;
    }

    /**
     * @brief operator != - overloaded not equal to operator so we can
     *                      compare iterators.
     * @param other - the other iterator being compared.
     * @return - returns true or false depending on the outcome of the
     *           comparison.
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
