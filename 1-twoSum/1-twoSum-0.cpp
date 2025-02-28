/*
      1. Two Sum
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> appeared;
        vector<int> out;

        for(int i=0; i < nums.size(); ++i) {
            // check if target-nums[i] is in appeared hash table
            if(appeared.find(target-nums[i]) != appeared.end())
                return {appeared[target-nums[i]], i};
            else appeared[nums[i]] = i; 
        }
        return {};
    }
};
