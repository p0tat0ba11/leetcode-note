/*
      110. Balanced Binary Tree
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
