/*
      543. Diameter of Binary Tree
*/
#include<bits/stdc++.h>
using namespace std;

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
