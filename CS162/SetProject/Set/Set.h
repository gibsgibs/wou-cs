#ifndef SET_H
#define SET_H
#include<iostream>
using namespace std;

template<class T>
class Set
{
private:
    T* set;
    int size;
    int numItems;

public:
    Set();
    Set(const Set<T> &other);
    Set<T>& operator=(const Set<T>& other);
    ~Set();
    void grow();
    bool contains(T item) const;
    void add(T item);
    int getSize() const;
    void remove(T item);
    void clear();
    T removeSmallest();
    bool operator==(const Set<T>& other) const;
    string toString() const;
    Set<T> intersectionWith(const Set<T>& other) const;
};
    template<class T>
    Set<T>::Set()
    {
        size = 8;
        numItems = 0;
        set = new T[size];
    }

    template<class T>
    Set<T>::Set(const Set<T> &other)
    {
        size = other.size;
        numItems = other.numItems;
        set = new T[size];
        for(int i = 0; i < numItems; i++)
        {
            set[i] = other.set[i];
        }
    }

    template<class T>
    void Set<T>::grow()
    {
        if(numItems >= size)
        {
            cout << "Ooops, have to grow..."
                 << endl;
            T* old = set;
            size = 2 * numItems;
            set = new T[numItems * 2];
            for(int i = 0; i < numItems; i++)
            {
                set[i] = old[i];
            }
            delete[] old;
        }
    }

    template<class T>
    bool Set<T>::contains(T item) const
    {
        int count = 0;
        for(int i = 0; i < numItems; i++)
        {
            if(set[i] != item)
            {
                count++;
            }
        }
        if(count != numItems)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template<class T>
    void Set<T>::add(T item)
    {
        grow();
        if(contains(item) == true)
        {
            cout << "Already Contained."
                 << endl;
        }
        else
        {
            set[numItems] = item;
            numItems++;
        }
    }

    template<class T>
    Set<T>::~Set()
    {
        delete[] set;
    }

    template<class T>
    int Set<T>::getSize() const
    {
        return numItems;
    }

    template<class T>
    void Set<T>::remove(T item)
    {
        if(contains(item) == true)
        {
            int loc = 0;
            for(int i = 0; i < numItems; i++)
            {
                if(set[i] == item)
                {
                    loc = i;
                }
            }
            for(int j = loc; j < numItems - 1; j++)
            {
                set[j] = set[j + 1];
            }
            numItems--;
        }
    }

    template<class T>
    void Set<T>::clear()
    {
        size = 0;
        numItems = 0;
    }

    template<class T>
    T Set<T>::removeSmallest()
    {
        int locSmallest = 0;
        for(int i = 1; i < numItems; i++)
        {
            if(set[locSmallest] > set[i])
            {
                locSmallest = i;
            }
        }
        T smallest = set[locSmallest];
        remove(set[locSmallest]);
        return smallest;
    }
    template<class T>
    bool Set<T>::operator==(const Set<T>& other) const
    {
        if(size == other.size && numItems == other.numItems)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template<class T>
    string Set<T>::toString() const
    {
        ostringstream oss("{}");
        oss << "{";
        for(int i = 0; i < numItems; i++)
        {
            oss << set[i];
            if(i != numItems - 1)
            {
                oss << ", ";
            }
        }
        oss << "}";
        return oss.str();
    }

    template<class T>
    Set<T>& Set<T>::operator=(const Set<T>& other)
    {
        if(set == other.set)
        {
            return *this;
        }
        size = other.size;
        numItems = other.numItems;

        for(int i = 0; i < other.numItems; i++)
        {
            set[i] = other.set[i];
        }
        return *this;
    }

    template<class T>
    Set<T> Set<T>::intersectionWith(const Set<T>& other) const
    {
        Set<T> intersect;
        for(int i = 0; i < numItems; i++)
        {
            for(int j = 0; j < other.numItems; j++)
            {
                if(set[i] == other.set[j])
                {
                    intersect.add(set[i]);
                }
            }
        }
        return intersect;
    }


#endif // SET_H
