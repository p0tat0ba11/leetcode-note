# 3. Longest Substring Without Repeating Characters

## Method
```cpp=
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int appear[256] = {};
        int longest=0;
        int left=0, right=0;

        while(right < s.length()) {
            appear[s[right]]++;

            while(appear[s[right]] > 1) {
                    --appear[s[left++]];
            }
            longest = max(longest, right-left+1);
            right++;
        }
        return longest;
    }
};
```