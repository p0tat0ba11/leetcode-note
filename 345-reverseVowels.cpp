/*
      345. Reverse Vowels of a String
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i < j) {
            if(!isVowel(s[i])) ++i;
            else if(!isVowel(s[j])) --j;
            else {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};
