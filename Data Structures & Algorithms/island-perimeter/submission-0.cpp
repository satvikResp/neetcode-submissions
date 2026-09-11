class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> adj(m * n);

        int v = 0;

        // graph
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    v++;

                    int id = i * n + j;

                    // Right
                    if(j + 1 < n && grid[i][j + 1] == 1) {

                        int next = i * n + (j + 1);

                        adj[id].push_back(next);
                        adj[next].push_back(id);
                    }

                    // Down
                    if(i + 1 < m && grid[i + 1][j] == 1) {

                        int next = (i + 1) * n + j;

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

        int perimeter = 4 * v - 2 * edges;

        return perimeter;
    }
};