/*
      15. 3Sum
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        for(int i=0; i < nums.size(); ++i) {
            // i != j
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=nums.size()-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) --r;
                else if(sum < 0) ++l;
                else {
                    output.push_back({nums[i], nums[l++], nums[r--]});
                    // j != k
                    while(l < r && nums[l] == nums[l-1]) ++l;
                }
            }
        }
        return output;
    }
};
