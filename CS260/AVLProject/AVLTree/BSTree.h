#ifndef BSTREE_H
#define BSTREE_H
#include "Iterator.h"

template<class T>
class BSTree
{
protected:
    TreeNode<T>* root;
    int size;
public:
    BSTree(); //no-arg constuctor
    ~BSTree(); //destuctor
    /**
     * @brief search - searches the binary search tree for the specified element
     * @param theElement - the element given as a parameter
     * @return - retuns true or false based on if it found the element
     */
    bool search(T theElement);
    /*New functon that was not in BSTproject; needed for proper implementation of AVL*/
    /**
     * @brief createNewNode - creates a new node on the heap containing the given element
     * @param theElement - the given element
     * @return - a poiter to the new node on the heap
     */
    TreeNode<T>* createNewNode(T theElement);
    /**
     * @brief searchHelper - a recursive helper function that is used in the search function, taking in the starting node, and the element
     * @param theElement - the element that we are looking for in the tree
     * @param theNode - the starting node (the root)
     * @return - a pointer to a TreeNode<T> so the search function can determin if it was found
     */
    TreeNode<T>* searchHelper(T theElement, TreeNode<T>* theNode);

    /**
     * @brief insert - insertes the given element into the binary search tree
     * @param theElement - the element given as a parameter
     * @return - returns true or false based on if the node was inserted
     */
    bool insert(T theElement);

    /**
     * @brief insertHelper - a recursive helper function that is used in the insert method, taking in the starting node, and the element
     * @param theElement - the element of the node we are inserting
     * @param theNode - the node that the functions starts at
     * @return - returns the node
     */
    TreeNode<T> *insertHelper(T theElement, TreeNode<T>* theNode);

    /**
     * @brief inOrderPrint - prints out the tree in order
     */
    void inOrderPrint();

    /**
     * @brief BSTtoVector - turns a tree into a vector of treeNodes<T>*
     * @return - returns a pointer to a vector of treeNode pointers on the heap
     */
    vector<TreeNode<T>*>* BSTtoVector();

    /**
     * @brief BSTtoVectorHelper - a recursive helper function used in the BSTtoVector function
     * @param tempVector - a temp vector that will be returned
     * @param theNode - the startign node (the root)
     * @return - return a pointer to a vector of TreeNode<T> pointers
     */
    vector<TreeNode<T>*>* BSTtoVectorHelper(vector<TreeNode<T> *> *tempVector, TreeNode<T>* theNode);

    /**
     * @brief isEmpty - checks to see if the tree is empty
     * @return - returns true or false depending on if the tree is empty
     */
    bool isEmpty() const;

    /**
     * @brief getSize - gets the size of the tree
     * @return  returns that size
     */
    int getSize() const;

    /**
     * @brief clear - clears the binary search tree by deleting all of the nodes.
     */
    void clear();

    /**
     * @brief clearHelper - a recursive function that is used in the clear fucntion that takes in a startign node
     * @param theNode - the startign node (the root)
     */
    void clearHelper(TreeNode<T>* theNode);

    /**
     * @brief begin - returns an iterator to the begining of a vector<T> that holds all the elements in the tree
     * @return - returns that iterator
     */
    Iterator<T> begin();

    /**
     * @brief end - creates an iterator to the end of the tree
     * @return - returns a NULL iterator
     */
    Iterator<T> end();

    /**
     * @brief fixHeight - fixes the height of each node depending on the height of its children, and if it is itself NULL
     * @param theNode - the starting node (the root)
     */
    void fixHeight(TreeNode<T>* theNode);
};

/*Implementation of the above methods*/

template<class T>
BSTree<T>::BSTree()
{
    root = NULL;
    size = 0;
}

template<class T>
BSTree<T>::~BSTree()
{
    clear(); //clears the tree for memory managment
}

template<class T>
TreeNode<T>* BSTree<T>::createNewNode(T theElement)
{
    TreeNode<T>* newNode = new TreeNode<T>(theElement);
    return newNode;
}

template<class T>
bool BSTree<T>::search(T theElement)
{
    TreeNode<T>* tempNode = searchHelper(theElement, root); //calls the helper fucntion
    if(tempNode == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<class T>
TreeNode<T>* BSTree<T>::searchHelper(T theElement, TreeNode<T>* theNode)
{
    if(theNode == NULL) //empty tree
    {
        return theNode;
    }
    else if(theElement == theNode->element) //the node contains the element
    {
        return theNode;
    }
    else if(theElement < theNode->element)
    {
        return searchHelper(theElement, theNode->left); //check the left child
    }
    else
    {
        return searchHelper(theElement, theNode->right); //check the right child
    }
}

template<class T>
bool BSTree<T>::insert(T theElement)
{
    if(root == NULL)
    {
        root = insertHelper(theElement, root); //calls the helper function
    }
    else
    {
        insertHelper(theElement, root);
    }
    size++;
    return true;
}

template<class T>
TreeNode<T>* BSTree<T>::insertHelper(T theElement, TreeNode<T>* theNode)
{
    if(theNode == NULL)
    {
        return createNewNode(theElement); //creates a new node on the heap
    }
    else if(theElement < theNode->element)
    {
        theNode->left = insertHelper(theElement, theNode->left); //check the left child
        fixHeight(theNode);
    }
    else
    {
        theNode->right = insertHelper(theElement, theNode->right); //check the right child
        fixHeight(theNode);
    }
    return theNode;
}

template<class T>
void BSTree<T>::inOrderPrint()
{
    vector<TreeNode<T>*>* list = BSTtoVector();
    typename vector<TreeNode<T>*>::iterator listIt = list->begin();
    cout << "---In order traversal---\n";
    for(; listIt < list->end(); listIt++)
    {
        cout << static_cast<TreeNode<T>*>(*listIt)->height
             << " ";
    }
    cout << endl;
    delete list;
}

template<class T>
vector<TreeNode<T>*>* BSTree<T>::BSTtoVector()
{
    vector<TreeNode<T>*>* returnVector = new vector<TreeNode<T>*>;
    returnVector = BSTtoVectorHelper(returnVector, root);
    return returnVector;
}

template<class T>
vector<TreeNode<T>*>* BSTree<T>::BSTtoVectorHelper(vector<TreeNode<T>*>* tempVector, TreeNode<T>* theNode)
{
    if(theNode != NULL)
    {
        BSTtoVectorHelper(tempVector, theNode->left);
        tempVector->push_back(theNode);
        BSTtoVectorHelper(tempVector, theNode->right);
    }
    return tempVector;
}

template<class T>
bool BSTree<T>::isEmpty() const
{
    if(size == 0 && root == NULL) //checks to see if the tree is empty
        return true;
    else
        return false;
}

template<class T>
int BSTree<T>::getSize() const
{
    return size; //favorite
}

template<class T>
void BSTree<T>::clear()
{
    clearHelper(root); //call to the helper function
    root = NULL; //sets the root to NULL
    size = 0; //sets the size to 0
}

template<class T>
void BSTree<T>::clearHelper(TreeNode<T>* theNode)
{
    if(theNode != NULL)
    {
        clearHelper(theNode->left); //traverses to the left
        clearHelper(theNode->right); // traverses to the right
        delete theNode; //deletes the node
    }
}

template<class T>
Iterator<T> BSTree<T>::begin()
{
    return Iterator<T>(this->root); //an iterator to the root
}

template<class T>
Iterator<T> BSTree<T>::end()
{
    return NULL;
}

template<class T>
void BSTree<T>::fixHeight(TreeNode<T> *theNode)
{
    if(theNode->left == NULL && theNode->right == NULL) //if both nodes are NULL, then the height is 0
    {
        theNode->height = 0;
    }
    else if(theNode->left == NULL) //if only the left is NULL, the height is the height of the right + 1
    {
        theNode->height = 1 + (theNode->right->height);
    }
    else if(theNode->right == NULL) //if only the right is NULL, the height is the height of the left + 1
    {
        theNode->height = 1 + (theNode->left->height);
    }
    else //otherwise, the height is the height of the larger height + 1
    {
        theNode->height = 1 + max(theNode->right->height,
                               theNode->left->height);
    }
}

#endif // BSTREE_H
