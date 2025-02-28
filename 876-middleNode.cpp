/*
      876. Middle of the Linked List
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        while(head) {
            nodes.push_back(head);
            head = head->next;
        }
        return nodes[nodes.size()/2];
    }
};
