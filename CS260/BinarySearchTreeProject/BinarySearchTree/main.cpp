#include "BSTree.h"

using namespace std;
int main()
{
    BSTree<int> myTree;
    myTree.clear();
    myTree.insert(10);
    myTree.insert(20);
    myTree.insert(30);
    myTree.insert(40);
    myTree.insert(50);
    myTree.insert(60);
    myTree.insert(50);
    myTree.insert(70);
    myTree.insert(80);
    myTree.insert(90);


    myTree.inOrderPrint();
    vector<TreeNode<int>*>* myVec = myTree.BSTtoVector();
    vector<TreeNode<int>*>::iterator myIt = myVec->begin();
    for(; myIt < myVec->end(); myIt++)
    {
        cout << static_cast<TreeNode<int>*>(*myIt)->height
             << " ";
    }

    return 0;
}
