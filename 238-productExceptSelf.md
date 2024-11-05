# 238. Product of Array Except Self

## Method
```cpp=
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 1);
        for(int i=0; i < nums.size()-1; ++i)
            product[i+1] = nums[i] * product[i];
        for(int i=nums.size()-1; i >= 1; --i) {
            nums[i-1] *= nums[i];
            product[i-1] *= nums[i];
        }
        return product;
    }
};
```