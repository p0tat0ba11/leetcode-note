/*
      3289. The Two Sneaky Numbers of Digitville
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> output;

        int cnts[101] = {};
        for(int num: nums) 
            cnts[num]++;
        
        for(int i=0; i < 101; ++i)
            if(cnts[i] == 2)
                output.push_back(i);
    
        return output;
    }
};
