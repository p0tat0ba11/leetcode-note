# 1. Two Sum

## Method 1 (One-pass Hash Table)

```cpp=
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> appeared; // key=val, value=index
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

## Method 2 (Binary Search)

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
