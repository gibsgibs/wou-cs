#ifndef AVLTREE_H
#define AVLTREE_H
#include "BSTree.h"
#include "AVLTreeNode.h"

template<typename T>
class AVLTree : public BSTree<T> //inhertits from BSTree
{
public:
    AVLTree();  //no-arg constuctor that uses BSTree's constructor
    /**
     * @brief insert - inserts a new node containing the element in to the tree using BST inset,
     *                 increments the size, and then balances the tree
     * @param theElement - the given element
     * @return - returns true or false based on if it inserted
     */
    bool insert(T theElement);
    /**
     * @brief getHeight - gets the height of the node
     * @param theNode - a pointer to the node we want the height of
     * @return - returns the height
     */
    int getHeight(AVLTreeNode<T>* theNode);
protected:
    /**
     * @brief createNewNode - creates a new node on the heap of the given element
     * @param theElement - the given element
     * @return - a pointer to that node
     */
    AVLTreeNode<T>* createNewNode(T theElement);
private:
//    void updateHeight(AVLTreeNode<T>* theNode);
    /**
     * @brief path - creates a path from the root to the node containing that element
     * @param theElement - the given element
     * @return - returns a vector of treeNode pointers
     */
    vector<AVLTreeNode<T>*> path(T theElement);
    /**
     * @brief balancePath - creats a path, and then balances that path based on
     *                      the balance factor of each node
     * @param theElement - the given element
     */
    void balancePath(T theElement);
    /**
     * @brief balanceFactor - calculates the balance factor based on the heights
     *                        of he child nodes
     * @param theNode - the given node we want the balance factor of
     * @return - the balance factor of the node
     */
    int balanceFactor(AVLTreeNode<T>* theNode);
    /**
     * @brief balanceLL - balances the tree using the given node and its parent
     *                    when the tree is left left heavy
     * @param A - the node we are given
     * @param parentOfA - the parent of the node we are given
     */
    void balanceLL(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA);
    /**
     * @brief balanceLR - balances the tree using the given node and its parent
     *                    when the tree is left right heavy
     * @param A - the node we are given
     * @param parentOfA - the parent of the node we are given
     */
    void balanceLR(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA);
    /**
     * @brief balanceRR - balances the tree using the given node and its parent
     *                    when the tree is right right heavy
     * @param A - the node we are given
     * @param parentOfA - the parent of the node we are given
     */
    void balanceRR(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA);
    /**
     * @brief balanceRL - balances the tree using the given node and its parent
     *                    when the tree is right left heavy
     * @param A - the node we are given
     * @param parentOfA - the parent of the node we are given
     */
    void balanceRL(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA);
};

/*---PUBLIC---*/
template<typename T>
AVLTree<T>::AVLTree()
{
    BSTree<T>(); //calls BST's constuctor
}

template<typename T>
bool AVLTree<T>::insert(T theElement)
{
    bool result = BSTree<T>::insert(theElement); //BST's insert
    if(result == true)
    {
        balancePath(theElement); //balances the tree
    }
    return result;
}

template<typename T>
int AVLTree<T>::getHeight(AVLTreeNode<T>* theNode)
{
    return theNode->height;
}

/*---PROTECTED---*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::createNewNode(T theElement) //this is not acutally used
{
    AVLTreeNode<T>* newNode = new AVLTreeNode<T>(theElement); //new node on the heap
    return newNode;
}

/*---PRIVATE---*/
//template<typename T>
//void AVLTree<T>::updateHeight(AVLTreeNode<T>* theNode)
//{
//    if(theNode->left == NULL && theNode->right == NULL)
//    {
//        theNode->height = 0;
//    }
//    else if(theNode->left == NULL)
//    {
//        theNode->height = 1 + (theNode->right->height);
//    }
//    else if(theNode->right == NULL)
//    {
//        theNode->height = 1 + (theNode->left->height);
//    }
//    else
//    {
//        theNode->height = 1 + max(theNode->right->height,
//                               theNode->left->height);
//    }
//}

template<typename T>
vector<AVLTreeNode<T>*> AVLTree<T>::path(T theElement)
{
    AVLTreeNode<T>* current = static_cast<AVLTreeNode<T>*>(this->root);
    vector<AVLTreeNode<T>*> treeVector;
    while(current != NULL) //as long as we have not reached the end of the tree
    {
        treeVector.push_back(current); //put the node in the vector
        if(theElement < current->element)
        {
            current = static_cast<AVLTreeNode<T>*>(current->left); //current = its left child
        }
        else if(theElement > current->element)
        {
            current = static_cast<AVLTreeNode<T>*>(current->right); //currents = its right child
        }
        else
            break;
    }
    return treeVector;
}

template<typename T>
void AVLTree<T>::balancePath(T theElement)
{
    vector<AVLTreeNode<T>*> treePath = path(theElement);
    AVLTreeNode<T>* temp;
    typename vector<AVLTreeNode<T>*>::iterator it = treePath.end() - 1; //makes an iterator to the last item in the vector
    for(; it >= treePath.begin(); it--) //as long as the iterator does not make past the begining
    {
        temp = *it; //sets temp = the node the iterator is pointing to
        if(balanceFactor(temp) <= -2 &&
          (balanceFactor(static_cast<AVLTreeNode<T>*>(temp->left)) == 0 ||
           balanceFactor(static_cast<AVLTreeNode<T>*>(temp->left)) == -1)) //case for left left case
        {
            balanceLL(temp, *(it - 1));
        }
        else if(balanceFactor(temp) >= 2 &&
               (balanceFactor(static_cast<AVLTreeNode<T>*>(temp->right)) == 0 ||
                balanceFactor(static_cast<AVLTreeNode<T>*>(temp->right)) == 1)) //case for right right case
        {
            balanceRR(temp, *(it - 1));
        }
        else if(balanceFactor(temp) <= -2 &&
               (balanceFactor(static_cast<AVLTreeNode<T>*>(temp->left)) == 0 ||
                balanceFactor(static_cast<AVLTreeNode<T>*>(temp->left)) == 1)) //case for left right case
        {
            balanceLR(temp, *(it - 1));
        }
        else if(balanceFactor(temp) >= 2 &&
               (balanceFactor(static_cast<AVLTreeNode<T>*>(temp->right)) == 0 ||
                balanceFactor(static_cast<AVLTreeNode<T>*>(temp->right)) == -1)) //case for right left case
        {
            balanceRL(temp, *(it - 1));
        }
    }
}

template<typename T>
int AVLTree<T>::balanceFactor(AVLTreeNode<T>* theNode)
{
    int bf; //the balance factor
    if(theNode->right != NULL && theNode->left != NULL) //neither node is null
    {
        bf = (theNode->right->height) - (theNode->left->height); //right height - left height
    }
    else if(theNode->right != NULL) //left is null
    {
        bf = (theNode->right->height) + 1; //right height
    }
    else if(theNode->left != NULL) //right is null
    {
        bf = ((theNode->left->height) * -1) - 1; //left height
    }
    else //both null
    {
        bf = 0;
    }
    return bf;
}

template<typename T>
void AVLTree<T>::balanceLL(AVLTreeNode<T> *A, AVLTreeNode<T> *parentOfA)
{
    AVLTreeNode<T>* B = static_cast<AVLTreeNode<T>*>(A->left); //B is A's left child
    if(A == this->root)
    {
        this->root = B; //root = B
    }
    else if(parentOfA->left == A) //if A is a left node
    {
        parentOfA->left = B; //set A's parent's left to B
    }
    else
    {
        parentOfA->right = B; //set A's parent's right to B
    }
    A->left = B->right; //set A's left to B's right
    B->right = A; //set B's right to A
    BSTree<T>::fixHeight(A);
    BSTree<T>::fixHeight(B);
}

template<typename T>
void AVLTree<T>::balanceLR(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA)
{
    AVLTreeNode<T>* B = static_cast<AVLTreeNode<T>*>(A->left); //B is A's left
    if(A->left->right->left != NULL) //if A's left's right's left child is not null
    {
        AVLTreeNode<T>* C = static_cast<AVLTreeNode<T>*>(B->right); //C is B's right
        AVLTreeNode<T>* D = static_cast<AVLTreeNode<T>*>(C->left); //D is C's left
        B->right = D; //set B's right to D
        C->left = B; //set C's left to B
        A->left = C; //set A's left to C
    }
    else
    {
        A->left = B->right; //set A's left to B's right
        B->right = NULL; //set B's right to null
        A->left->left = B; //set A's left's left to B
    }
    balanceLL(A, parentOfA); //call the left left balance
}

template<typename T>
void AVLTree<T>::balanceRL(AVLTreeNode<T>* A, AVLTreeNode<T>* parentOfA)
{
    AVLTreeNode<T>* B = static_cast<AVLTreeNode<T>*>(A->right); //B is A's right
    if(A->right->left->right != NULL) //if A's right's left's right child is not null
    {
        AVLTreeNode<T>* C = static_cast<AVLTreeNode<T>*>(B->left); //C is B's left
        AVLTreeNode<T>* D = static_cast<AVLTreeNode<T>*>(C->right); //D is C's right
        B->left = D; //set B's left to D
        C->right = B; //set C's right = B
        A->right = C; //set A's right = C
    }
    else
    {
        A->right = B->left; //set A's right to B's left
        B->left = NULL; //set B's left to null
        A->right->right = B; //set A's right's right to B
    }
    balanceRR(A, parentOfA); //call the right right balance
}

template<typename T>
void AVLTree<T>::balanceRR(AVLTreeNode<T> *A, AVLTreeNode<T> *parentOfA)
{
    AVLTreeNode<T>* B = static_cast<AVLTreeNode<T>*>(A->right);//B is A's right
    if(A == this->root)
    {
        this->root = B; //set the root to B
    }
    else if(parentOfA->right == A) //if A is a right child
    {
        parentOfA->right = B; //set A's parent's right to B
    }
    else
    {
        parentOfA->left = B; //set A's parent's left to B
    }
    A->right = B->left; //set A's right to B's left
    B->left = A; //sets B's left to A
    BSTree<T>::fixHeight(A);
    BSTree<T>::fixHeight(B);
}

#endif // AVLTREE_H

