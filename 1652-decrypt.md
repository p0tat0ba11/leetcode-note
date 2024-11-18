# 1652. Defuse the Bomb

## Method
```cpp=
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>output(code.size(), 0);
        if(k > 0) {
            for(int i=0; i < code.size(); ++i) {
                for(int j=1; j <= k; ++j)
                    output[i] += code[(i+j)%code.size()];
            }
        }
        else if(k < 0) {
            k += code.size();
            for(int i=0; i < code.size(); ++i) {
                for(int j=code.size()-1; j >= k; --j) 
                    output[i] += code[(i+j)%code.size()];
            }
        }
        return output;
    }
};
```