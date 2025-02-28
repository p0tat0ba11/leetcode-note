/*
      53. Maximum Subarray
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int large=nums[0];
        for(int i=1; i < nums.size(); ++i) {
            nums[i] = max(nums[i-1]+nums[i], nums[i]);
            large = max(large, nums[i]);
        }
        return large;
    }
};
