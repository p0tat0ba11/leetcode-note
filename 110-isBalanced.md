# 110. Balanced Binary Tree
## Description
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

## Method
```cpp=
class Solution {
public:
    bool bottomUp(TreeNode* root, int& height) {
        if(!root) {
            height=-1;
            return true;
        }

        int left, right;
        if(bottomUp(root->left, left) && bottomUp(root->right, right) &&
            abs(left - right) < 2) {
                height = max(left, right) + 1;
                return true;
            }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int height;
        return bottomUp(root, height);
    }
};
```