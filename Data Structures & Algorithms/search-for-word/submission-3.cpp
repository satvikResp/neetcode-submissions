class Solution {
public:

    bool func(vector<vector<char>>& board, string word,int row ,int col,string &res,int word_idx){
        if(word_idx==word.size()){
            if(res==word) return true;
            return false;
        }
        if(row>=board.size() || col>=board[0].size()) return false;
        //left
        if(col-1>=0 && board[row][col-1]==word[word_idx]){
            char ch = board[row][col - 1];

            board[row][col - 1] = '#';
            res += ch;

            if (func(board, word, row, col - 1, res, word_idx + 1))
                return true;

            res.pop_back();
            board[row][col - 1] = ch;
        }
        
        //right
        if(col+1<board[0].size() && board[row][col+1]==word[word_idx]){
            char ch = board[row][col + 1];

            board[row][col + 1] = '#';
            res += ch;

            if (func(board, word, row, col + 1, res, word_idx + 1))
                return true;

            res.pop_back();
            board[row][col + 1] = ch;
        }

        //top
        if(row-1>=0 && board[row-1][col]==word[word_idx]){
            char ch = board[row - 1][col];

            board[row - 1][col] = '#';
            res += ch;

            if (func(board, word, row - 1, col, res, word_idx + 1))
                return true;

            res.pop_back();
            board[row - 1][col] = ch;
        }

        //bottom
        if(row+1<board.size() && board[row+1][col]==word[word_idx]){
            char ch = board[row + 1][col];

            board[row + 1][col] = '#';
            res += ch;

            if (func(board, word, row + 1, col, res, word_idx + 1))
                return true;

            res.pop_back();
            board[row + 1][col] = ch;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string res="";

        int r=board.size();
        int c=board[0].size();
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(board[row][col]==word[0]){
                    char ch = board[row][col];

                    board[row][col] = '#';
                    res += ch;
                    if(func(board,word,row,col,res,1)) return true;
                    res.pop_back();
                    board[row][col] = ch;
                }
            }
        }
        return false;
    }
};
