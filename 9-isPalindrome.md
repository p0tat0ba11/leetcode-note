# 9. Palindrome Number

## Method
```cpp=
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x%10 == 0)) return false;
        int revert = 0;
        while(x > revert) {
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        return x == revert || x == revert/10;
    }
};
```