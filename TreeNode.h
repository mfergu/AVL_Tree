#ifndef TreeNode_h
#define TreeNode_h

class TreeNode{
  public:
    TreeNode();
    TreeNode(int nu_val) : element(nu_val)
      {}
    int element;
    TreeNode *left;
    TreeNode *right;
};
#endif
  
