# 1431. Kids With the Greatest Number of Candies

## Method

```cpp=
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest=0;
        vector<bool> greatestCandies(candies.size(), false);
        for(int candy: candies) greatest = max(greatest, candy);
        for(int i=0; i < candies.size(); ++i) {
            if(candies[i] + extraCandies >= greatest)
                greatestCandies[i] = true;
        }
        return greatestCandies;
    }
};
```