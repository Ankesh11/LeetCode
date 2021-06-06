//Problem : https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int first_row = 1;
        int first_col = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        first_row=0;
                    }
                    else{
                        matrix[i][0] = 0;
                    }
                    
                    if(j==0){
                        first_col = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(first_row==0){
            for(int i=0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        if(first_col==0){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};

//Time Complexity : O(m*n)
//Space Complexity : O(1)