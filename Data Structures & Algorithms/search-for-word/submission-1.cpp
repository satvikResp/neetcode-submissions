class Solution {
public:
    bool func(vector<vector<char>>& board,int i,int j,int index,string& word){
        if(index==word.size()) return true;

        //top
        if(i-1>=0 && board[i-1][j]==word[index]){
            char prev= board[i-1][j];
            board[i-1][j]='#';
            if(func(board,i-1,j,index+1,word)) return true;
            board[i-1][j]=prev;
        }

        //bottom
        if(i+1<board.size()&& board[i+1][j]==word[index]){
            char prev= board[i+1][j];
            board[i+1][j]='#';
            if(func(board,i+1,j,index+1,word)) return true;
            board[i+1][j]=prev;
        }

        //left
        if(j-1>=0 && board[i][j-1]==word[index]){
            char prev= board[i][j-1];
            board[i][j-1]='#';
            if(func(board,i,j-1,index+1,word)) return true;
            board[i][j-1]=prev;
        }

        //right
         if(j+1<board[0].size()&& board[i][j+1]==word[index]){
            char prev= board[i][j+1];
            board[i][j+1]='#';
            if(func(board,i,j+1,index+1,word)) return true;
            board[i][j+1]=prev;
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
     
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    char prev= board[i][j];
                    board[i][j]='#';
                    if(func(board,i,j,1,word)) return true;
                    board[i][j]=prev;
                    continue;
                }
            }
        }
        return false;
    }
};
