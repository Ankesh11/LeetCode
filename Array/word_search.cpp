//Problem : https://leetcode.com/problems/word-search/

class Solution {
public:
    bool search(vector<vector<char>>& board, int i, int j, string& word, int index){
        if(index==word.length()){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if(i>=m || j>=n || i<0 || j<0){
            return false;
        }
        if(board[i][j]==word[index]){
            board[i][j]='#';
            if(search(board, i+1, j, word, index+1) || search(board, i, j+1, word, index+1) || search(board, i-1, j, word, index+1) || search(board, i, j-1, word, index+1)){
                return true;
            }
            board[i][j] = word[index];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(search(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

//Time Complexity : O(m^2*n^2)
//Space Complexity : O(world_length) - recursion call stack