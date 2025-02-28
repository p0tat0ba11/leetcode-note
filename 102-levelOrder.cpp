/*
      102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> output;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()) {
            int size = bfs.size();
            vector<int> level;
            for(int i=0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();  
                level.push_back(node->val);
                if(node->left) bfs.push(node->left);
                if(node->right) bfs.push(node->right);
            }
            output.push_back(level);
        }
        return output;
    }
};
