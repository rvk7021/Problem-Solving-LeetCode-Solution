#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void solve(vector<vector<int> >matrix)
    {
        // count all the zeroes in row then zero the corresponding column 
        // similarly find all the zeroes in column then zero the corresponding row
        // space will be O(n+m) where time will be approx O(m*n)
          set<int>row,col;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]==0){
                        row.insert(i);
                        col.insert(j);
                    }
                }
            }
            for(auto it:row){
                for(int k=0;k<matrix[it].size();k++){
                    matrix[it][k]=0;
                }
            }
             for(auto it:col){
                for(int k=0;k<matrix.size();k++){
                    matrix[k][it]=0;
                }
            }
        }
};