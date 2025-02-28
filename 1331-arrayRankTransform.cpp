/*
      1331. Rank Transform of an Array
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) return arr;

        vector<pair<int, int>> ranks(arr.size(), {0, 0});
        for (int i = 0; i < arr.size(); ++i)
            ranks[i] = {arr[i], i};
        // sort the 'ranks' vector based on the values
        sort(ranks.begin(), ranks.end());

        arr[ranks[0].second] = 1;
        for (int i = 1; i < ranks.size(); ++i) {
            if (ranks[i].first == ranks[i-1].first) { 
                // duplicate value, assign the same rank
                arr[ranks[i].second] = arr[ranks[i-1].second];
            } else {
                arr[ranks[i].second] = arr[ranks[i-1].second] + 1;
            }
        }
        return arr;
    }
};
