/*
      266. Palindrome Permutation
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int appear[26] = {};
    
        for(char ch: s) {
            ++appear[ch-'a'];
        }
        int odd = 0;
        for(int i=0; i < 26; ++i) 
            if(appear[i] % 2 == 1) {
                cout << appear[i] << endl;
                odd++;
            }
        return odd <= 1;
    }
};