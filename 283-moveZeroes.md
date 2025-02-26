# 283. Move Zeroes

## Method

```cpp=
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;

        int nonZero=0;
        for(int i=0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                if(nonZero < i) nonZero=i+1;
                for(; nonZero < nums.size() && nums[nonZero]==0; ++nonZero);
                if(nonZero >= nums.size()) return;
                swap(nums[i], nums[nonZero]);
                nonZero++;
            }
        }
    }
};
```