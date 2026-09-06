class Solution {
public:
    bool isvalid(vector<string>&board,int row,int col,int n){
        //hme dusre queen ki presence sirf uper wali hi check krni hai kyunki top to down hi place krrhe hai na

        //kisi dabbe /location ke directly uper queen to nhi hai
        for(int r=0;r<row;r++){
            if(board[r][col]=='Q')
            return false;
        }

        //diagonal  check
        

        // upper-left diagonal
        for(int r=row-1, c=col-1; r>=0 && c>=0; r--, c--){
            if(board[r][c]=='Q')
                return false;
        }

        // upper-right diagonal
        for(int r=row-1, c=col+1; r>=0 && c<n; r--, c++){
            if(board[r][c]=='Q')
                return false;
        }
                return true;
            }
    void func(vector<string>&board,int row,int n,vector<vector<string>>&ans){
        
        //base con
        if(row>=n){
            ans.push_back(board);
            return;
        }


        for(int col=0;col<n;col++){  //ye chsron col dekhegea dalke
            if(isvalid(board,row,col,n)){ //valid hai tbhi daliyo 
            board[row][col]='Q';
            func(board,row+1,n,ans);
            board[row][col]='.';
            }
           
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        //                   |       |
        //                string     each string
        vector<vector<string>>ans;
        func(board,0,n,ans);
        return ans;
    }
};
