#ifndef HASHSET_H
#define HASHSET_H
#include <string>
#include "DLList.h"
#include <unordered_set>

typedef std::unordered_set<std::string> stringset;
template<typename T>
class HashSet
{
public:
    HashSet();
    double hashFunction(T data);
    bool insert(T data);
    void clear();
    bool find(T data);
    bool isEmpty();
    bool erase(T data);
    int getSize();
private:
    int size;
    const static int tableSize = 101;
    DLList<T>* hashTable [tableSize];
};

template<typename T>
HashSet<T>::HashSet()
{
    size = 0;
    for(int i = 0; i < 101; i++)
    {
        hashTable[i] = nullptr;
    }
}
template<typename T>
double HashSet<T>::hashFunction(T data)
{
    stringset myset;
    stringset::hasher fn = myset.hash_function();
    double hash = (abs(fn(data)));
    return fmod(hash, tableSize);
}
template<typename T>
bool HashSet<T>::insert(T data)
{
    bool result = false; //set the bool to false to start
    double index = hashFunction(data); //hash the data
    if(find(data) == true)
    {
        //the data is already in the heap, so don't do anything
    }
    else if(hashTable[static_cast<int>(index)] == NULL) //if the list at this index is empty
    {
        DLList<T>* list = new DLList<T>();          //make a new index
        list->add(data);                            //add the data to the list
        hashTable[static_cast<int>(index)] = list;  //set the table index pointer to the
        size++;
        result = true;
    }
    else //if the lsit at the index is not empty
    {
        hashTable[static_cast<int>(index)]->add(data);
        size++;
        result = true;
    }
    return result;
}
template<typename T>
void HashSet<T>::clear()
{
    for(int i = 0; i < tableSize; i++) //loop through the table
    {
        if(hashTable[i] != NULL) //if the list at the index is not empty
        {
            hashTable[i]->clear(); //use DLL clear
            hashTable[i] = NULL; //set the index to NULL
        }
    }
    size = 0;
}
template<typename T>
bool HashSet<T>::find(T data)
{
    bool result = false; //make a bool and set it to false
    double index = hashFunction(data); //hash the data
    if(hashTable[static_cast<int>(index)] != NULL) //if the list at the index is not empty
    {
        result = hashTable[static_cast<int>(index)]->contains(data); //call DLL contains
    }
    return result;
}
template<typename T>
bool HashSet<T>::isEmpty()
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<typename T>
bool HashSet<T>::erase(T data)
{
    double index = hashFunction(data); //hash the data
    bool result = find(data); //run the find function and store the result
    if(result == true)
    {
        hashTable[static_cast<int>(index)]->remove(data); //call DLL remove
        size--;
    }
    return result;
}
template<typename T>
int HashSet<T>::getSize()
{
    return size;
}
#endif // HASHSET_H
