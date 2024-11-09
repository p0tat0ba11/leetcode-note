# 1213. Intersection of Three Sorted Arrays

## Method
```cpp=
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> output;
        int i1=0, i2=0, i3=0;
        while(i1 < arr1.size() && i2 < arr2.size() && i3 < arr3.size()) {
            if(arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]) {
                output.push_back(arr1[i1]);
                ++i1, ++i2, ++i3;
            } else {
                if(arr1[i1] < arr2[i2]) ++i1;
                if(arr2[i2] < arr3[i3]) ++i2;
                if(arr3[i3] < arr1[i1]) ++i3;
            }
        }
        return output;
    }
};
```