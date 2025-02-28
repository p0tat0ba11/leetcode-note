/*
      150. Evaluate Reverse Polish Notation
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> integers;
        for(string& str: tokens) {
            if(isdigit(str[0]) || (str.length()>1 && isdigit(str[1])))
                integers.push(stoi(str));
            else{
                int y = integers.top();
                integers.pop();
                int x = integers.top();
                integers.pop();
                switch(str[0]) {
                    case '+':
                        integers.push(x+y);
                        break;
                    case '-':
                        integers.push(x-y);
                        break;
                    case '*':
                        integers.push(x*y);
                        break;
                    case '/':
                        // if(y == 0) return false; // when divide by zero
                        integers.push(x/y);
                        break;
                }
            }
        }
        return integers.top();
    }
};
