# 14. Longest Common Prefix

## Method
```cpp=
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix=0;
        while(prefix < strs[0].size()) {
            for(int i=1; i < strs.size(); ++i)
                if(strs[i][prefix] != strs[i-1][prefix]) 
                    return strs[i-1].substr(0, prefix);
            ++prefix;
        }
        return strs[0];
    }
};
```