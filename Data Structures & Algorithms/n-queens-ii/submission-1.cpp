class Solution {
public:
     bool isvalid(int i,int j,vector<string>&formation){

        for(int row=i-1;row>=0;row--){
            if(formation[row][j]=='Q') return false;
        }
        //diagonaly check krna hai sirf 
        //left diagonal
        int row=i-1;
        int col=j-1;
        for(;row>=0 && col>=0;row--,col--){
            if(formation[row][col]=='Q') return false;
        }

        //right diagonal
        row=i-1;
        col=j+1;
        for(;row<formation.size() && col<formation[0].size();row--,col++){
            if(formation[row][col]=='Q') return false;
        }
        return true;

    }
    void func(int &ans,vector<string>&formation,int n,int row){
        if(row==n){
            ans++;
            return;
        }
    
        //ek ek karke row check kro
        for(int j=0; j<n; j++){

        if(isvalid(row, j, formation)){

            formation[row][j] = 'Q';

            func(ans, formation, n, row + 1);

            formation[row][j] = '.';
        }
        }
        return;
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string>formation(n,string(n, '.'));
        int placed_q=0;
        func(ans,formation,n,placed_q);
        return ans;
    }
};

