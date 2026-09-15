class Solution {
public:

    vector<vector<int>> directions{
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    bool dfs_p(vector<vector<int>>& heights, int row, int col,
               vector<vector<bool>>& visited) {

        // Pacific boundary
        if(row == 0 || col == 0) {
            return true;
        }

        visited[row][col] = true;

        for(auto dir : directions) {

            int r = row + dir[0];
            int c = col + dir[1];

            if(r >= 0 && r < heights.size() &&
               c >= 0 && c < heights[0].size() &&
               !visited[r][c] &&
               heights[r][c] <= heights[row][col]) {

                if(dfs_p(heights, r, c, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs_a(vector<vector<int>>& heights, int row, int col,
               vector<vector<bool>>& visited) {

        // Atlantic boundary
        if(row == heights.size()-1 ||
           col == heights[0].size()-1) {

            return true;
        }

        visited[row][col] = true;

        for(auto dir : directions) {

            int r = row + dir[0];
            int c = col + dir[1];

            if(r >= 0 && r < heights.size() &&
               c >= 0 && c < heights[0].size() &&
               !visited[r][c] &&
               heights[r][c] <= heights[row][col]) {

                if(dfs_a(heights, r, c, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> pacific;
        vector<vector<int>> atlantic;

        int rows = heights.size();
        int cols = heights[0].size();

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                // Fresh visited for Pacific
                vector<vector<bool>> visitedP(
                    rows, vector<bool>(cols, false)
                );

                if(dfs_p(heights, i, j, visitedP)) {
                    pacific.push_back({i,j});
                }

                // Fresh visited for Atlantic
                vector<vector<bool>> visitedA(
                    rows, vector<bool>(cols, false)
                );

                if(dfs_a(heights, i, j, visitedA)) {
                    atlantic.push_back({i,j});
                }
            }
        }

        // Intersection
        vector<vector<int>> ans;

        for(auto p : pacific) {

            for(auto a : atlantic) {

                if(p[0] == a[0] && p[1] == a[1]) {
                    ans.push_back(p);
                }
            }
        }

        return ans;
    }
};