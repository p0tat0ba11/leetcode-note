/*
      1133. Largest Unique Number
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int cnts[1001] = {};
        for(int num: nums) ++cnts[num];
        for(int i=1000; i >= 0; --i) 
            if(cnts[i]==1) return i;
        return -1;
    }
};
