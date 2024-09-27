# 1. Two Sum
## Description
In this problem, we need to find the indices of two numbers whose sum equals a given target.

## Method 1 (One-pass Hash Table)
I store the numbers in a hash table along with their indices. Then, for each number, I can calculate the difference between the target and the current number to check for a match in the hash table.

```cpp=
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
```

## Method 2 (Two-Pointer Search)
First, I store all the numbers along with their indices in a vector and sort the vector based on the values. Then, I employ a two-pointer approach to find the two numbers that add up to the target.

```cpp=
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for(int i=0; i < nums.size(); ++i)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());

        int l=0, r=v.size()-1;
        while(l < r) {
            if(v[l].first + v[r].first > target) --r;
            else if(v[l].first + v[r].first < target) ++l;
            else return {v[l].second, v[r].second};
        }
        return {};
    }
};
```

## Question 
### Why is method 1 slower than method 2?
