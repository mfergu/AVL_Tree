#include "BST.h"
using namespace std;

int main()
{
    int arr[7];
  for(int i = 0; i<7; i++)
    arr[i] = i;
//    arr[i] = (i+2) * 7 % 17; 
    
  BST *test = new BST(arr, 7);
  
  cout << "\n testing preorder" << endl;
  test->preorder();
  cout << "\n testing inorder" << endl;
  test->inorder();
  cout << "\n testing postorder" << endl;
  test->postorder();
  cout << "\n";
  cout << "\n testing remove" << endl;
  test->remove(14);
  cout << "\n testing preorder" << endl;
  test->preorder();
  cout << "\n testing inorder" << endl;
  test->inorder();
  cout << "\n testing postorder" << endl;
  test->postorder();
  cout << "\n";

  return 0;
}
