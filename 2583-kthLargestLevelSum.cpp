/*
      2583. Kth Largest Sum in a Binary Tree
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> sums;

        queue<TreeNode*> curLevelNodes;
        curLevelNodes.push(root);
        while (!curLevelNodes.empty()) {    
            long long sum = 0;
            int size = curLevelNodes.size();
            // iterate through this level
            for (int i = 0; i < size; i++) {
                TreeNode* curNode = curLevelNodes.front();
                curLevelNodes.pop();
                sum += curNode->val;
                
                // append next level nodes
                if (curNode->left != NULL)
                    curLevelNodes.push(curNode->left);
                if (curNode->right != NULL) 
                    curLevelNodes.push(curNode->right);
            }
            sums.push(sum);
            if (sums.size() > k) sums.pop();
        }
        if (sums.size() < k) return -1;
        return sums.top();
    }
};
