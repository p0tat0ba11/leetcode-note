/*
      13. Roman to Integer
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convert(char ch) {
        switch(ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        };
        return 0;
    }
    int romanToInt(string s) {
        int val=0;
        for(int i=0; i < s.length(); ++i) {
            if(i + 1 < s.length() && convert(s[i+1]) > convert(s[i])) 
                val -= convert(s[i]);
            else
                val += convert(s[i]);
        }
        return val;
    }
};
