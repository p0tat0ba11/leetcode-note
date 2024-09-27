# 20. Valid Parentheses
The problem involves checking if the brackets are matched correctly and of the same type. 

## Method 
I use a map (implemented as red-black trees) to associate the closing brackets with their corresponding opening brackets. When I encounter a closing bracket, I push it onto a stack. For an opening bracket, I check if the stack is empty and if the top of the stack matches the correct type of bracket.

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
