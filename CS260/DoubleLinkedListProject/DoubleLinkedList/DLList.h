#ifndef DLLIST_H
#define DLLIST_H
#include "Node.h"
#include "DLListIterator.h"
#include <stdexcept>

template<class T>
class DLList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DLList() //zero parameter constuctor
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /**
     * @brief add - adds a new node containing the
     *              given element to the end of the
     *              list.
     * @param theElement - the data being passed in.
     */
    void add(T theElement)
    {
        Node<T>* node = new Node<T>(theElement);
        if(size == 0) //if the list is empty
        {
            tail = node;
            head = node;
            size++;
        }
        else //otherwise do this for all cases
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
            size++;
        }
    }

    /**
     * @brief add - adds a node containing the given element to the
     *              given index of the list.
     * @param index - the place the node is being added.
     * @param theElement - the data being passed in.
     */
    void add(int index, T theElement)
    {
        Node<T>* node = new Node<T>(theElement);
        try
        {
            if(size < index || index < 0) //making sure the index valid
            {
                throw out_of_range("Invalid index:");
            }
        }
        catch(...)
        {
            cout << "\n--------------------------\n"
                 << "Exception - Invalid input:\n"
                 << "--------------------------\n";
            exit(0);
        }
        if(index == 0) //if the index is the head
        {
            if(size == 0)
            {
                head = node;
                tail = node;
                size++;
            }
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
                size++;
            }
        }
        else if(index == size) //if the index is the tail
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
            size++;
        }
        else //all other cases
        {
            Node<T>* tempNode = head;
            int i = 0;
            while(i < index)
            {
                tempNode = tempNode->next;
                i++;
            }
            tempNode->prev->next = node;
            node->prev = tempNode->prev;
            tempNode->prev = node;
            node->next = tempNode;
            size++;
        }
    }

    /**
     * @brief clear - clears the entire list, deleting all the nodes.
     */
    void clear()
    {
        Node<T>* tempNode;
        while(head != tail) //loops through deleting nodes as it goes
        {
            tempNode = tail;
            tail = tempNode->prev;
            delete tempNode;

        }
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }
    }

    /**
     * @brief contains - returns true if the list contains the
     *                   givin element being passed in.
     * @param theElement - the data being passed in.
     * @return - returns true or false, based on whether or not the
     *           list contains the element.
     */
    bool contains(T theElement) const
    {
        bool result = false;
        if(size == 0) //no size means empty list, which means no containment
        {
            result = false;
        }
        else if(head->element == theElement) //if the head contains the element
        {
            result = true;
        }
        else if(tail->element == theElement) //if the tail contains the element
        {
            result = true;
        }
        else //all other cases
        {
            Node<T>* tempNode = head;
            int i = 0;
            while(i < size)
            {
                if(tempNode->element == theElement)
                {
                    result = true;
                }
                tempNode = tempNode->next;
                i++;
            }
        }
        return result;
    }

    /**
     * @brief get - returns the element of the node at the given index.
     * @param index - the position of the node we want the element
     *                from.
     * @return - the element of the node.
     */
    T get(int index) const
    {
        if(index == 0) //if the index is the head
        {
            return head->element;
        }
        else if(index == size - 1) //if the index is the tail
        {
            return tail->element;
        }
        else //all other cases
        {
            Node<T>* tempNode = head;
            int i = 1;
            while(i <= index)
            {
                tempNode = tempNode->next;
                i++;
            }
            return tempNode->element;
        }
    }

    /**
     * @brief isEmpty - checks to see is the list is empty.
     * @return - returns true if the list is empty, and false
     *           is it is not.
     */
    bool isEmpty()
    {
        bool result = false;
        if(size == 0) //just needs to check is the size is 0
        {
            result = true;
        }
        return result;
    }

    /**
     * @brief remove - removes the element that is passed in
     *                 as a parameter from the list.
     * @param theElement - the data being passed in.
     * @return - true or false, based on if it removed the node.
     */
    bool remove(T theElement)
    {
        if(contains(theElement)) //making sure the element is in the list
        {
            Node<T>* tempNode = head;
            while(tempNode->element != theElement) //looping through to find said element
            {
                tempNode = tempNode->next;
            }
            if(tail->element == theElement && size > 1) //if it is the tail, and the size is greater than 1
            {
                tail = tail->prev;
                delete tail->next;
                size--;
                return true;
            }
            else if(head->element == theElement && size > 1) //if it is the head, and the size is greater than 1
            {
                head = head->next;
                delete head->prev;
                size--;
                return true;
            }
            else //all other cases
            {
                tempNode->next->prev = tempNode->prev;
                tempNode->prev->next = tempNode->next;
                delete tempNode;
                size--;
                return true;
            }
        }
        else
            return false;
        }

    /**
     * @brief removeAt - removes the node at the specified index.
     * @param index - the index of the node that is being deleted.
     * @return - the element of the node.
     */
    T removeAt(int index)
    {
        try
        {
            if(size <= index || index < 0) //making sure we have a valid index
            {
                throw out_of_range("Invalid index:");
            }
        }
        catch(...)
        {
            cout << "\n--------------------------\n"
                 << "Exception - Invalid input:\n"
                 << "--------------------------\n";
            exit(0);
        }
        Node<T>* tempNode = head;
        T theElement;
        if(index == size - 1) //if the tail is the index, delete the tail and reset pointers
        {
            tempNode = tail;
            tail = tempNode->prev;
            tempNode->prev->next = NULL;
            theElement = tempNode->element;
            delete tempNode;
            size--;
            return theElement;
        }
        else if(index == 0) //if the head is the index, delete the head and reset pointers
        {
            head = tempNode->next;
            tempNode->next->prev = NULL;
            theElement = tempNode->element;
            delete tempNode;
            size--;
            return theElement;
        }
        else //all other cases, and generic pointer reset
        {
            int i = 0;
            while(i < index)
            {
                tempNode = tempNode->next;
                i++;
            }
            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;
            size--;
            theElement = tempNode->element;
            delete tempNode;
            return theElement;
        }
    }

    /**
     * @brief getSize - literally gets the size of the list.
     * @return - the size of the list.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief begin - an iterator to the head of the list.
     * @return - returns the iterator to he head.
     */
    DLListIterator<T> begin()
    {
        return DLListIterator<T>(head);
    }

    /**
     * @brief end - an iterator that points to the tail of the list.
     * @return - returns the iterator to the tail.
     */
    DLListIterator<T> end()
    {
        return DLListIterator<T>(tail);
    }
};

#endif // DLLIST_H
