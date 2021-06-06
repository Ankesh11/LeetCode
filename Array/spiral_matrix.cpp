//Problem : https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int beg_row = 0, beg_col = 0, end_row = m -1, end_col = n-1;
        
        while(1){
            //Inserting begenning row;
            for(int i=beg_col;i<=end_col;i++){
                res.push_back(matrix[beg_row][i]);
            }
            beg_row++;
            
            if(beg_row>end_row){
                break;
            }
            //Inserting end column
            for(int i=beg_row; i<=end_row; i++){
                res.push_back(matrix[i][end_col]);
            }
            end_col--;
            if(beg_col > end_col){
                break;
            }
            
            //Extracting end row
            for(int i=end_col;i>=beg_col;i--){
                res.push_back(matrix[end_row][i]);
            }
            end_row--;
            
            if(end_row < beg_row){
                break;
            }
            //Extracting beginning column
            for(int i=end_row;i>=beg_row;i--){
                res.push_back(matrix[i][beg_col]);
            }
            beg_col++;
            
            if(beg_col > end_col){
                break;
            }
        }
        return res;
        
    }
};