/*
      20. Valid Parentheses
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> parent = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        
        stack<char> right;
        for(char ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') right.push(ch);
            else {
                if(right.empty()) return false;        
                if(right.top() != parent[ch]) return false;
                right.pop();
            }
        }
        if(!right.empty()) return false;
        return true;
    }
};
