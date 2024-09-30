# 383. Ransom Note

## Method

```cpp=
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length() < ransomNote.length()) return false;
        int alpha[26] = {};
        for(int i=0; i < magazine.length(); ++i) {
            alpha[magazine[i]-'a']++;
            if(i < ransomNote.length()) alpha[ransomNote[i]-'a']--;
        }
        for(int i=0; i < 26; ++i)
            if(alpha[i] < 0) return false;
        return true;
    }
};
```