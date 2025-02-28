/*
      57. Insert Interval
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>output;
        int start=newInterval[0];
        int end=newInterval[1];

        int i=0;
        // before newInterval
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
            output.push_back(intervals[i++]);

        // overlapping interval
        while(i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        output.push_back({start, end});

        // after overlapping
        while(i < intervals.size())
            output.push_back(intervals[i++]);
        return output;
    }
};
