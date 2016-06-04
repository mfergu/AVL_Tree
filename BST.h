#ifndef BST_H
#define BST_H
#include "TreeNode.h"
#include <iostream>

class BST{
  public:
    BST();
    BST(int[], int); //input an array of ints with size of array
    bool search(int); //returns true if the element is in the tree
    bool insert(int); //returns true if the element is inserted correctly
    bool remove(int); //returns true if the element is removed correctly
    TreeNode createNewNode(int); 
    void preorder();
    void inorder(); 
    void postorder();
    int getSize();
    TreeNode* getRoot();
    
    
  Protected:
    TreeNode *root;
    int size;
    void preorder( TreeNode*); 
    void inorder( TreeNode*); 
    void postorder( TreeNode*);

#endif
