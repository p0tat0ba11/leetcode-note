/*
      169. Majority Element
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int half = nums.size()/2;
        for(int num: nums) {
            if(++cnts[num] > half) return num;
        }
        return -1;
    }
};
