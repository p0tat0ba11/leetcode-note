/*
      199. Binary Tree Right Side View
*/
#include<bits/stdc++.h>
using namespace std;

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pending;
        pending.push(root);
        vector<int>right;
        while(!pending.empty()) {
            int row = pending.size();
            right.push_back(pending.back()->val);
            for(int i=0; i < row; ++i) {
                TreeNode* node = pending.front();
                pending.pop();
                if(node->left) pending.push(node->left);
                if(node->right) pending.push(node->right);
            }
        }
        return right;
    }
};