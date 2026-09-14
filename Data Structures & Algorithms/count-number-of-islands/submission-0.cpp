class Solution {
public:
    void calculateislands(vector<vector<char>>& grid,int row,int col){
        //base condition
        if(row>=grid.size() || col>=grid[0].size()) return ;
        //right
        if(col+1<grid[0].size() && grid[row][col+1]=='1'){
       
            grid[row][col+1]='#';
            calculateislands(grid,row,col+1);
        }

        //down 
        if(row+1<grid.size() && grid[row+1][col]=='1'){
            
            grid[row+1][col]='#';
            calculateislands(grid,row+1,col);
        }
        //left
        if(col-1>=0 && grid[row][col-1]=='1'){
            
            grid[row][col-1]='#';
            calculateislands(grid,row,col-1);
        }
        //up 
        if(row-1>=0 && grid[row-1][col]=='1'){
            grid[row-1][col]='#';
            calculateislands(grid,row-1,col);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    grid[i][j]='#';
                    calculateislands(grid,i,j);
                }
            }
        }
        return cnt;
    }
};
