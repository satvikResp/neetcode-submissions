class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>rowmap;
        unordered_map<int,unordered_set<char>>colmap;
        unordered_map<int,unordered_set<char>>matmap;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

            if(board[i][j]=='.'){
                continue;
            }
            char digit=board[i][j];
            int index=(i/3)*3 + (j/3);
            if(rowmap[i].contains(board[i][j])||colmap[j].contains(board[i][j])||matmap[index].contains(board[i][j])==true){
                return false;
            }
            rowmap[i].insert(board[i][j]);
            colmap[j].insert(board[i][j]);
            matmap[index].insert(board[i][j]);
            
            }


        }
        return true;
        
    }
};
