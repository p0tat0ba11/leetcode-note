/*
      1957. Delete Characters to Make Fancy String
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string output(s.length(), ' ');
        int j=0;
        for(int i=0; i < s.length(); ++i) {
            if(i+1 < s.length() && s[i] == s[i+1] && s[i] == s[i+2])
                continue;
            else output[j++] = s[i];
        }
        output.resize(j);
        return output;
    }
};
