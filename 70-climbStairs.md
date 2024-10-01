# 70. Climbing Stairs

## Method
```cpp=
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        int history[45] = {};
        history[0]=1, history[1]=2;
        for(int i=2; i < n; ++i) {
            history[i] = history[i-2]+history[i-1];
        }
        return history[n-1];
    }
};
```