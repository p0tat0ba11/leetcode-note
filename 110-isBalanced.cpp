/*
      110. Balanced Binary Tree
*/
#include<bits/stdc++.h>
using namespace std;

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
