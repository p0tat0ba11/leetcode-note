/*
      226. Invert Binary Tree
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
