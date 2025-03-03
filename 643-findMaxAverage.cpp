/*
      643. Maximum Average Subarray I
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i < k; ++i) {
            sum += nums[i];
        }
        int maxAvg = sum;
        for(int i=k; i < nums.size(); ++i) {
            sum = sum - nums[i-k] + nums[i];
            maxAvg = max(maxAvg, sum);
        }
        return double(maxAvg)/k;

    }
};