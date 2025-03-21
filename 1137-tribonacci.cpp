/*
      1137. N-th Tribonacci Number
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int arr[38] = {};
        arr[1]=arr[2]=1;
        for(int i=3; i <= n; ++i) {
            arr[i] = arr[i-3]+arr[i-2]+arr[i-1];
        }
        return arr[n];
    }
};