/*
      235. Lowest Common Ancestor of a Binary Search Tree
*/
#include<bits/stdc++.h>
using namespace std;

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
