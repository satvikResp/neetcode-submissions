class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board,int row ,int col,vector<vector<bool>>&visited){

      visited[row][col]=true;

       for(auto dir :directions){
        int r=row+dir[0];
        int c=col+dir[1];

        if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]=='O' && !visited[r][c]){
            dfs(board,r,c,visited);
        }
       }
    }
    void bfs(vector<vector<char>>& board,int row ,int col,vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        
        q.push({row,col});
        while(!q.empty()){
            auto current_coordinates=q.front();
            q.pop();
            visited[current_coordinates.first][current_coordinates.second]=true;
            for(auto dir :directions){
                int r=current_coordinates.first+dir[0];
                int c=current_coordinates.second+dir[1];
                if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]=='O' && !visited[r][c]){
                    q.push({r,c});
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        //sirf boundary wale O dekh and jo unse connected hai unko true krde aur baki sare false reh jayenge aur unko phir x bana dege
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        //top wali boundary  row=0 and col 1 2 3 4 5 
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                bfs(board,0,i,visited);
            }
        }
        //left boundary row=1 2 3 4 5 and col =0
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                bfs(board,i,0,visited);
            }
        }

        //bottom boundary row=last row and col 1 2 3 4 5 
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O'){
                bfs(board,board.size()-1,i,visited);
            }
        }

        //right boundary row 1 2 3 4 5 and col last col
        // right boundary
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O'){
                bfs(board,i,board[0].size()-1,visited);
            }
        }


        //ab false walon ko x banado agar nhi hai to 

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visited[i][j]==false && board[i][j]!='X'){
                    board[i][j]='X';
                }
            }
        }

    }
};