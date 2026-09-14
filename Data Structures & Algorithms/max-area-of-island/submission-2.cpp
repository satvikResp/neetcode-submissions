class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int & area){
        
 

    // right
    if(col + 1 < grid[0].size() && grid[row][col + 1] == 1){
        area++;
        grid[row][col + 1] = 0;
        dfs(grid, row, col + 1, area);
    }    

    // down
    if(row + 1 < grid.size() && grid[row + 1][col] == 1){
        area++;
        grid[row + 1][col] = 0;
        dfs(grid, row + 1, col, area);
    }
    // left
    if(col - 1 >= 0 && grid[row][col - 1] == 1){
        area++;
        grid[row][col - 1] = 0;
        dfs(grid, row, col - 1, area);
    }
    // up
    if(row - 1 >= 0 && grid[row - 1][col] == 1){
        area++;
        grid[row - 1][col] = 0;
        dfs(grid, row - 1, col, area);
    }    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxarea = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j]==1){
                grid[i][j] = 0;
                int area=1;
                dfs(grid,i,j,area);
                maxarea = max(maxarea, area);
            }
        }
    }
    return maxarea;

  }
};
