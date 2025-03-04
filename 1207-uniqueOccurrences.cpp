/*
      1207. Unique Number of Occurrences
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
      bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> occurs;
            for(int num: arr)
            occurs[num]++;
            
            map<int, int> numOfOccurs;
            for(pair<int, int> occur: occurs)
            if(++numOfOccurs[occur.second] > 1) return false;
            return true;
      }
};