class Solution {
public:

    void calculateislands(vector<vector<int>>& grid,
                          int row, int col, int &area) {

        // invalid cell / water
        if(row < 0 || row >= grid.size() ||
           col < 0 || col >= grid[0].size() ||
           grid[row][col] == 0) {
            return;
        }

        // visited
        grid[row][col] = 0;

        // current land count
        area++;

        // right
        calculateislands(grid, row, col + 1, area);

        // down
        calculateislands(grid, row + 1, col, area);

        // left
        calculateislands(grid, row, col - 1, area);

        // up
        calculateislands(grid, row - 1, col, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxarea = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 1) {

                    int area = 0;

                    calculateislands(grid, i, j, area);

                    maxarea = max(maxarea, area);
                }
            }
        }

        return maxarea;
    }
};