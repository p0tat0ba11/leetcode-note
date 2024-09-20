# 20. Valid Parentheses

## Method 
```cpp=
class Solution {
public:
    bool isValid(string s) {
        map<char, char> parent = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        
        stack<char> right;
        for(char ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') right.push(ch);
            else {
                if(right.empty()) return false;        
                if(right.top() != parent[ch]) return false;
                right.pop();
            }
        }
        if(!right.empty()) return false;
        return true;
    }
};
```

## Question
### Why is using `map` faster than using `unordered_map` in this case?
