# 242. Valid Anagram

## Method
```cpp=
class Solution {
public:
    bool isAnagram(string s, string t) {
        // s.len may not equal to t.len
        if(s.length() != t.length()) return false;

        // s and t consist of lowercase English letters
        vector<int> appear(26, 0);
        for(int i=0; i < s.length(); ++i) {
            ++appear[s[i]-'a'];
            --appear[t[i]-'a'];
        }
        for(int cnt: appear)
            if(cnt) return false;
        return true;
    }
};
```