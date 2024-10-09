# 104. Maximum Depth of Binary Tree

## Method
```cpp=
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int countLeft = 1 +  maxDepth(root->left);
        int countRight =1 +  maxDepth(root->right);
        return max(countLeft ,countRight);
    }
};
```