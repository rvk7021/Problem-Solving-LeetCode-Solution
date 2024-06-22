#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int directions[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {   
                int lives = 0;
                for(int k = 0; k < 8; k++) {
                    int delRow = i + directions[k][0];
                    int delCol = j + directions[k][1];
                    if(delRow >= 0 && delRow < m && delCol >= 0 && delCol < n) {
                        if(board[delRow][delCol] == 1) lives++;
                    }
                }
                if(board[i][j] == 1) {
                    if(lives < 2 || lives > 3) ans[i][j] = 0; 
                    else ans[i][j] = 1; 
                } else {
                    if(lives == 3) ans[i][j] = 1;
                }
            }
        }

        board = ans;
        
        for(auto& row : board) {
            for(int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};
