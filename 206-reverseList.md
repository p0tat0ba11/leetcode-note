# 206. Reverse Linked List

## Method

```cpp=
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if(!cur) return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverse(cur, next);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
```