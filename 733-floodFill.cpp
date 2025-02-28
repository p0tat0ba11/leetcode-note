/*
      733. Flood Fill
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fill(vector<vector<int>>& image, int sr, int sc, int color, int origin) {
        if(image[sr][sc] == origin)
            image[sr][sc] = color;
        else return image;
        
        if(sr+1 < image.size())
            fill(image, sr+1, sc, color, origin);
        if(sr-1 >= 0)
            fill(image, sr-1, sc, color, origin);
        if(sc+1 < image[0].size()) 
            fill(image, sr, sc+1, color, origin);
        if(sc-1 >= 0)
            fill(image, sr, sc-1, color, origin);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        return fill(image, sr, sc, color, image[sr][sc]);
    }
};
