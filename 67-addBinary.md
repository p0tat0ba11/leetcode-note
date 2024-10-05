# 67. Add Binary

## Method

```cpp=
class Solution {
public:
    string addBinary(string a, string b) {
    if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;
    else if (b.size() < a.size()) b = string(a.size() - b.size(), '0') + b;

    int carry = 0;
    string result(a.size()+1, '0');
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i+1] = (sum % 2) + '0'; 
        carry = sum / 2; 
    }

    if (carry) result[0] = char(carry + '0');
    else result = result.substr(1, result.length()); 
    return result;
    }
};
```