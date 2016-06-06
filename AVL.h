#ifndef AVL_H
#define AVL_H
#include "BST.h"
#include "AVLTreeNode.h"
#include <algorithm>
#include <vector>

class AVLTree : public BST{

  public:
    AVLTree()
      {}
    AVLTree(int[], int);
    AVLTreeNode* createNewNode(int);
    bool insert(int);
    int getDiff(AVLTreeNode*);
    void updateHeight(AVLTreeNode*);
    void balancePath(int);
    int balanceFactor(AVLTreeNode*);
    void balanceLL(TreeNode*, TreeNode*);
    void balanceLR(TreeNode*, TreeNode*);
    void balanceRR(TreeNode*, TreeNode*);
    void balanceRL(TreeNode*, TreeNode*);
    bool remove(int);
    
};
#endif
    
