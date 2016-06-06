#include "AVL.h"
using namespace std;

AVLTree::AVLTree()
{}

AVLTree::AVLTree(int arr[], int size)
{
  for(int i = 0; i<size; i++)
    insert(arr[i]);
}

AVLTreeNode AVLTree::createNewNode(int nu_val)
{
  return new AVLTreeNode(nu_val);
}

bool AVLTree::insert(int insert_me)
{
  successful = BST::insert( insert_me);
  if(!successful)
    return false; 
  else
    BalancePath( insert_me);

  return true;
}

int AVLTree::getDiff(AVLTreeNode* node)
{
  int leftTree = node->left->height;
  int rightTree = node->right->height;
  int balanceFactor = leftTree - rightTree;
  return balanceFactor;
}
  
void AVLTree::updateHeight(AVLTreeNode* node)
{
  //node is a leaf
  if (node->left == nullptr && node->right == nullptr)
    node->height = 0;
  else if( node->left == nullptr)
    node->height = 1 + node->right->height;
  else if( node->reight == nullptr)
    node->height = 1 + node->left->height;
  else
    node->height = 1 + ( node->left->height > node->right->height ?\
      node->left->height : node->right->height);
}

void AVLTree::balancePath(AVLTreeNode* node)
{
  vector<AVLTreeNode*> path;
  AVLTreeNode* temp = root;
  while( temp!=node)
  {
    path.push_back(temp);
    if(node->element < temp->element)
      temp = temp->left;
    else
      temp = temp->right;
  }

  while(path.size() > 0)
  {
    int balanceFactor = getDiff(node);
    if( balanceFactor > 1) 
    {
      if( getDiff(node->left) > 0)
        balanceLL(node, path.front());
     else
        balanceLR(node, path.front());
    }
    else if( balanceFactor < -1)
    {
      if( getDiff(node->right) > 0)
        balanceRR(node, path.front());
      else
        balanceRL(node, path.front());
    }

    node = path.front();
    path.pop_back();
    
  }
}

void AVLTree::balanceLL(TreeNode* A, TreeNode* parentOfA)
{
  AVLTreeNode* B = A->left;
  if(A == root)
    B = root;
  else
  {
    if( parentOfA->left == A)
      parentOfA->left = B;
    else
      parentOfA->right = B;
  }
  
  A->left = B->right;
  B->right = A;
  updateHeight(A);
  updateHeight(B);
}
  
void AVLTree::balanceLR(TreeNode* A, TreeNode* parentOfA)
{
  AVLTreeNode* B = A->left;
  AVLTreeNode* C = B->right;
  
  if(A == root)
  {
    root = C;
  }
  else
  {
    if(parentOfA->left == A)
      parentOfA->left = C;
    else
      parentOfA->right = C;
  }

  A->left = C->right;
  B->right = C->left;
  C->left = B;
  C->right = A;

  updateHeight(A);
  updateHeight(B);
  updateHeight(C);
}
    
void balanceRR(TreeNode* A, TreeNode* parentOfA)
{
  TreeNode* B = A->right;
  
  if(A == root)
    root = B;
  else
  {
    if( parentOfA->left == A)
      parentOfA->left = B;
    else
      parentOfA->right = B;
  }
  
  A->right = B->left;
  updateHeight(A);
  updateHeight(B);
}

void balanceRL(TreeNode* A, TreeNode* parentOfA) 
{
  TreeNode B = A->right;
  TreeNode C = B->left;
  
  if( A==root)
    root = C;
  else
  {
    if( parentOfA->left == A)
      parentOfA->left = C;
    else
      parentOfA->right = C; 
  }

  A->right = C->left;
  B->left = C->right;
  C->left = A;
  C->right = B;

  updateHeight(A);
  updateHeight(B);
  updateHeight(C);
}

bool AVLTree::remove(int element)
{
  if(root == nullptr)
    return false;
  
