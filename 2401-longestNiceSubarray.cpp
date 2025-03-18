/*
      2401. Longest Nice Subarray
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;
        int left = 0; // left of the window
        int maxLen = 0;

        for(int right = 0; right < nums.size(); ++right) {
            // remove the number shares bits with window
            while((nums[right] & usedBits) != 0) {
                usedBits ^= nums[left++]; 
            }
            usedBits |= nums[right];
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};