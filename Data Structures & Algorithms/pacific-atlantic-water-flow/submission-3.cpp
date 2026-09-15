class Solution {
public:

    vector<vector<int>> directions{
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    void dfs_p(vector<vector<int>>& heights, int row, int col,
               vector<vector<bool>>& pacificVisited) {

        pacificVisited[row][col] = true;

        for(auto dir : directions) {

            int r = row + dir[0];
            int c = col + dir[1];

            if(r >= 0 && r < heights.size() &&
               c >= 0 && c < heights[0].size() &&
               !pacificVisited[r][c] &&
               heights[r][c] >= heights[row][col]) {

                dfs_p(heights, r, c, pacificVisited);
            }
        }
    }

    void dfs_a(vector<vector<int>>& heights, int row, int col,
               vector<vector<bool>>& atlanticVisited) {

        atlanticVisited[row][col] = true;

        for(auto dir : directions) {

            int r = row + dir[0];
            int c = col + dir[1];

            if(r >= 0 && r < heights.size() &&
               c >= 0 && c < heights[0].size() &&
               !atlanticVisited[r][c] &&
               heights[r][c] >= heights[row][col]) {

                dfs_a(heights, r, c, atlanticVisited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacificVisited(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlanticVisited(
            rows, vector<bool>(cols, false)
        );

        // Pacific: top row
        for(int j = 0; j < cols; j++) {
            dfs_p(heights, 0, j, pacificVisited);
        }

        // Pacific: left column
        for(int i = 0; i < rows; i++) {
            dfs_p(heights, i, 0, pacificVisited);
        }

        // Atlantic: bottom row
        for(int j = 0; j < cols; j++) {
            dfs_a(heights, rows - 1, j, atlanticVisited);
        }

        // Atlantic: right column
        for(int i = 0; i < rows; i++) {
            dfs_a(heights, i, cols - 1, atlanticVisited);
        }

        // Intersection
        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(pacificVisited[i][j] &&
                   atlanticVisited[i][j]) {

                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};