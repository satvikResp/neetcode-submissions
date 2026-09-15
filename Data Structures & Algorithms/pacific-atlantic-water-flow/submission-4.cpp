class Solution {
public:

    vector<vector<int>> directions{
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    // COMMON DFS
    void dfs(vector<vector<int>>& heights,
             int row,
             int col,
             vector<vector<bool>>& visited) {

        visited[row][col] = true;

        for(auto dir : directions) {

            int r = row + dir[0];
            int c = col + dir[1];

            if(r >= 0 && r < heights.size() &&
               c >= 0 && c < heights[0].size() &&
               !visited[r][c] &&
               heights[r][c] >= heights[row][col]) {

                dfs(heights, r, c, visited);
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

        // 👇 YAHAN Pacific boundary coordinates choose ho rahe hain

        // Top row: row = 0
        for(int j = 0; j < cols; j++) {
            dfs(heights, 0, j, pacificVisited);
        }

        // Left column: col = 0
        for(int i = 0; i < rows; i++) {
            dfs(heights, i, 0, pacificVisited);
        }


        // 👇 YAHAN Atlantic boundary coordinates choose ho rahe hain

        // Bottom row: row = rows - 1
        for(int j = 0; j < cols; j++) {
            dfs(heights, rows - 1, j, atlanticVisited);
        }

        // Right column: col = cols - 1
        for(int i = 0; i < rows; i++) {
            dfs(heights, i, cols - 1, atlanticVisited);
        }


        // 👇 YAHAN har coordinate check ho raha hai
        // ki dono oceans tak reachable hai ya nahi

        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(pacificVisited[i][j] &&
                   atlanticVisited[i][j]) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};