class Solution {
public:
    bool func(vector<vector<char>>& board, string word, int idx, int row, int col, vector<vector<int>> &visited){
        if(idx == word.size()) return true;
        int n = board.size();
        int m = board[0].size();
        
        if(row < 0 || col <0 || row >= n || col >= m || visited[row][col] == 1){
            return false;
        }
        if(word[idx] != board[row][col] )return false;
        
        visited[row][col] = 1;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(func(board, word, idx+1, nrow,ncol, visited) == true) return true;
        }
        visited[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
      
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( board[i][j] == word[0] && func(board, word, 0, i, j,visited) == true) return true;
            }
        }       
        return false;
    }
};