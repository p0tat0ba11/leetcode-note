# 543. Diameter of Binary Tree
## Description
This problem is to find the longest path between  any two nodes in a tree.

## Method
```cpp=
class Solution {
public:
    int traverse(TreeNode* root, int& diameter) { 
        if(!root) return 0;
        int left = traverse(root->left, diameter);
        int right = traverse(root->right, diameter);

        diameter = max(diameter, left+right);
        return max(right, left)+1;
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        traverse(root, diameter);
        return diameter;
    }
};
```