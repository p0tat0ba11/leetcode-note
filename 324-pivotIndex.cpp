/*
      724. Find Pivot Index
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right=0; 
        for(int i=1; i < nums.size(); ++i)
            right += nums[i];
        for(int i=1; i < nums.size(); ++i) {
            if(left == right) return i-1;
            left += nums[i-1];
            right -= nums[i];  
        }
        return left==right? nums.size()-1: -1;
    }
};