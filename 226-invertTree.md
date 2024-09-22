# 226. Invert Binary Tree

## Method
```cpp=
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(root->right) invertTree(root->right);
        if(root->left) invertTree(root->left);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        return root;
    }
};
```