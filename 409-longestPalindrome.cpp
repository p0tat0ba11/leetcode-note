/*
      409. Longest Palindrome
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int arr[58] = {}; // store number of alphabets
        for(char ch: s)
            ++arr[ch-'A'];

        bool odd = false; // there can be only one odd number in the middle
        int longest = 0;
        for(int i=0; i < 58; ++i) {
            if(arr[i]%2) { // odd number
                if(odd) longest += arr[i]-1;
                else {
                    longest += arr[i];
                    odd = true;
                }
            }
            else { // even number
                longest += arr[i];
            } 
        }
        return longest;
    }
};
