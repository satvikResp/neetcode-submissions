class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> adj(m * n);
        vector<bool> visited(m * n, false);

        int nodes = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    nodes++;

                    int id = i * n + j;

                    visited[id] = true;

                    // Up
                    if(i - 1 >= 0 &&
                       grid[i - 1][j] == 1 &&
                       visited[(i - 1) * n + j] == false) {

                        int next = (i - 1) * n + j;

                        adj[id].push_back(next);
                        adj[next].push_back(id);
                    }

                    // Down
                    if(i + 1 < m &&
                       grid[i + 1][j] == 1) {

                        int next = (i + 1) * n + j;

                        adj[id].push_back(next);
                        adj[next].push_back(id);
                    }

                    // Left
                    if(j - 1 >= 0 &&
                       grid[i][j - 1] == 1 &&
                       visited[i * n + (j - 1)] == false) {

                        int next = i * n + (j - 1);

                        adj[id].push_back(next);
                        adj[next].push_back(id);
                    }

                    // Right
                    if(j + 1 < n &&
                       grid[i][j + 1] == 1) {

                        int next = i * n + (j + 1);

                        adj[id].push_back(next);
                        adj[next].push_back(id);
                    }
                }
            }
        }

        int degree = 0;

        for(int i = 0; i < m * n; i++) {
            degree += adj[i].size();
        }

        int edges = degree / 2;

        int perimeter = 4 * nodes - 2 * edges;

        return perimeter;
    }
};