/*
      392. Is Subsequence
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()) return false;
        int appear[26] = {};
        int j=0;
        for(int i=0; i < s.length(); ++i) {
            while(j < t.length() && s[i] != t[j]) ++j;
            if(j >= t.length()) return false;
            ++j;
        }
        return true;
    }
};
