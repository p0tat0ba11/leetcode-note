# 238. Product of Array Except Self

## Method
```cpp=
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str(word1.length()+word2.length(), ' ');
        int i=0, i1=0, i2=0;
        while(i1 < word1.length() || i2 < word2.length()) {
            if(i1 < word1.length()) {
                str[i++] = word1[i1++];
            }
            if(i2 < word2.length()) {
                str[i++] = word2[i2++];
            }
        }
        return str;
    }
};
```