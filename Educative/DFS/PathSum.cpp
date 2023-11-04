using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum, int currSum) {
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr && currSum+root->val == sum){
            return true;
        }
        if(root->left == nullptr && root->right == nullptr && currSum+root->val != sum){
            return false;
        }
        
        return hasPath(root->left,sum, currSum+root->val) || hasPath(root->right,sum, currSum+root->val);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23, 0) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16, 0) << endl;
}