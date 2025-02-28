/*
      542. 01 Matrix
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int row=0; row < mat.size(); ++row) {
            for(int col=0; col < mat[0].size(); ++col) {
                if(mat[row][col] == 0) continue;
                int val = mat.size() * mat[0].size(); // maximum value
                val = row > 0? min(val, mat[row-1][col]): val; // down
                val = col > 0? min(val, mat[row][col-1]): val; // left
                mat[row][col] = val+1;
            }
        }
        for(int row=mat.size()-1; row >= 0; --row) {
            for(int col=mat[0].size()-1; col >= 0; --col) {
                if(mat[row][col] == 0) continue;
                int val = mat.size() * mat[0].size();
                val = row+1 < mat.size()? min(val, mat[row+1][col]): val; // up
                val = col+1 < mat[0].size()? min(val, mat[row][col+1]): val; // right
                mat[row][col] = min(mat[row][col], val+1);
            }
        }
        return mat;
    }
};
