class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxarea = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 1) {

                    int area = 0;
                    queue<pair<int,int>> q;

                    grid[i][j] = 0;
                    q.push({i,j});

                    while(!q.empty()) {

                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        area++;

                        // right
                        if(col + 1 < grid[0].size() &&
                           grid[row][col + 1] == 1) {
                            grid[row][col + 1] = 0;
                            q.push({row, col + 1});
                        }

                        // down
                        if(row + 1 < grid.size() &&
                           grid[row + 1][col] == 1) {
                            grid[row + 1][col] = 0;
                            q.push({row + 1, col});
                        }

                        // left
                        if(col - 1 >= 0 &&
                           grid[row][col - 1] == 1) {
                            grid[row][col - 1] = 0;
                            q.push({row, col - 1});
                        }

                        // up
                        if(row - 1 >= 0 &&
                           grid[row - 1][col] == 1) {
                            grid[row - 1][col] = 0;
                            q.push({row - 1, col});
                        }
                    }

                    maxarea = max(maxarea, area);
                }
            }
        }

        return maxarea;
    }
};