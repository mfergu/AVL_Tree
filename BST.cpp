#include "BST.h"
using namespace std;

BST::BST()
{}

BST::BST(int input[], int size)
{
  for(int i = 0; i<size; size++)
    insert(input[i]);
}

bool BST::search(int find_me)
{
  TreeNode *current = root;
  while(current!=null)
  {
    if(find_me < current->element)
      current = current->left;
    else if (find_me > current->element)
      current = current->right;
    else
      return true;
  }
  return false;
}

bool BST::insert(int insert_me)
{
  if(root == nullptr)
    root = createNewNode(insert_me);
  else
  {

    TreeNode *parent = nullptr;
    TreeNode *current = root;
  
    while(current !=nullptr)
      if(insert_me < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if(insert_me > current->element)
      {
        parent = current;
        current = current->right;
      }
      else 
        return false;

    if(insert_me < parent->element)
      parent->left = createNewNode(insert_me);
    else
      parent->right = createNewNode(insert_me);
  }
  
  size++;
  return true;
}

TreeNode* BST::createNewNode( int value)
{
  return new TreeNode(value);
}

void BST::preorder()
{
  preorder(root);
} 
        
void BST::inorder()
{
  inorder(root);
} 

void BST::postorder()
{
  postorder(root);
} 

void BST::preorder(TreeNode *root)
{
  if(root == nullptr)
    return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}
  
void BST::inorder(TreeNode *root)
{
  if(root == nullptr)
    return;
  preorder(root->left);
  cout << root->element << " ";
  preorder(root->right);
}
               
void BST::postorder(TreeNode *root)
{
  if(root == nullptr)
    return;
  preorder(root->left);
  preorder(root->right);
  cout << root->element << " ";
}

int BST::getSize()
{
  return size;
}

TreeNode* BST::getRoot()
{
  return root;
}

bool BST::remove(int remove_me)
{
  TreeNode* parent = nullptr;
  TreeNode* current = root;
  
  while(current !=nullptr)
    if(remove_me<current->element)
    {
      parent = current;
      current = current->left;
    }
    else if(remove_me > current->element)
    {
      parent = current;
      current = current->right;
    }
    else 
