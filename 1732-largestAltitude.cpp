/*
      1732. Find the Highest Altitude
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = gain[0];
        int highest=max(0, altitude);
        for(int i=1; i < gain.size(); ++i) {
            altitude += gain[i];
            highest=max(altitude, highest);
        }
        return highest;
    }
};