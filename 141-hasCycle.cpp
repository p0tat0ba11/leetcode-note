/*
      141. Linked List Cycle
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* dubl=head;
        while(dubl && dubl->next) {
            head=head->next;
            dubl=dubl->next->next;
            if(head==dubl) return true;
        }
        return false;
    }
};
