/*
      1429. First Unique Number
*/
#include<bits/stdc++.h>
using namespace std;

class FirstUnique {
public:
    unordered_map<int, int> cnts;
    queue<int> records;
    FirstUnique(vector<int>& nums) {
        cnts = unordered_map<int, int>();
        records = queue<int>();
        for(int num: nums) {
            if(++cnts[num] <= 1)
                records.push(num);
        }
    }
    
    int showFirstUnique() {
        while(!records.empty())
            if(cnts[records.front()] == 1) return records.front();
            else records.pop();
        return -1;
    }
    
    void add(int value) {
        if(++cnts[value] <= 1)
            records.push(value);
    }
};
