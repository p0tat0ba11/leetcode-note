/*
      235. Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        if(p->val > root->val && q->val < root->val ||
            p->val < root->val && q->val > root->val) return root;

        return p->val < root->val && q->val < root->val?
            lowestCommonAncestor(root->left, p, q):
            lowestCommonAncestor(root->right, p, q);
    }
};
