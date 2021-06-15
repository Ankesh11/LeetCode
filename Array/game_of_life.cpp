//Problem : https://leetcode.com/problems/game-of-life/

class Solution {
public:
    
    void gameOfLife(vector<vector<int>>& board) {
        int next_neigh_x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int next_neigh_y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> temp_board = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live_neigh = 0;
                int dead_neigh = 0;
                
                for(int k=0;k<8;k++){
                    int neigh_i = i+next_neigh_x[k];
                    int neigh_j = j+next_neigh_y[k];
                    if(neigh_i < 0 || neigh_i >= m || neigh_j <0 || neigh_j >=n){
                        continue;
                    }
                    if(temp_board[neigh_i][neigh_j] == 0){
                        dead_neigh++;
                    }
                    else{
                        live_neigh++;
                    }
                }
                
                if(temp_board[i][j]==1){
                    if(live_neigh<2){
                        board[i][j] = 0;
                    }
                    else if(live_neigh>3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(live_neigh==3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};

//Time Complexity : O(m*n)
//Space Complexity : O(m*n)