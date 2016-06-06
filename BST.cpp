#include "BST.h"
using namespace std;

BST::BST()
{}

BST::BST(int input[], int size)
{
  for(int i = 0; i<size; i++)
    insert(input[i]);
}

bool BST::search(int find_me)
{
  TreeNode *current = root;
  while(current!=nullptr)
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
  cout << "\n inserting:" << insert_me;
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
  cout << "\n removing:" << remove_me;
  TreeNode* parent = nullptr;
  TreeNode* current = root;
  
  while(current !=nullptr)
  {
    if(remove_me < current->element)
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
      break;
  }

  if( current == nullptr)
    return false;

  //if current has no left child
  if( current->left == nullptr)
  {
    //connect the parent with the right child of the current node
    if( parent == nullptr)
      root = current->right;
    else
    {
      if(remove_me < parent->element)
        parent->left = current->right;
      else
        parent->right = current->right;
    }
  }
  //the current node has a left child
  else
  {
    TreeNode* parentOfRightMost = current;
    TreeNode* rightMost = current->left;
  
    //locate the right most node of the left subtree
    while( rightMost->right != nullptr)
    {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right;
    }
  
    current->element = rightMost->element;

    if( parentOfRightMost->right == rightMost)
      parentOfRightMost->right = rightMost->left;
    else
      parentOfRightMost->left = rightMost->left;
  }
  
  size--;
  return true;
}
