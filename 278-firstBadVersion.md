# 278. First Bad Version

```cpp=
class Solution {
public:
    int firstBadVersion(int n) {
        long long int f=1, t=n;
        while(t-f > 1) {
            cout << (f+t)/2 << endl;
            if(isBadVersion((f+t)/2)) t = (f+t)/2;
            else f = (f+t)/2;
        }
        return isBadVersion(f)? f: t;
    }
};
```