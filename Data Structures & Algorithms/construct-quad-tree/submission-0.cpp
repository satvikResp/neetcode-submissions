class Solution {
public:

    Node* solve(vector<vector<int>>& grid,
                int r1, int r2, int c1, int c2) {

        // Check whether current region has same values
        bool same = true;

        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] != grid[r1][c1]) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        // If all values are same -> leaf node
        if (same) {
            return new Node(grid[r1][c1], true);
        }

        // Current region is mixed -> divide into 4
        int midRow = (r1 + r2) / 2;
        int midCol = (c1 + c2) / 2;

        Node* root = new Node(1, false);

        // Top Left
        root->topLeft =
            solve(grid, r1, midRow, c1, midCol);

        // Top Right
        root->topRight =
            solve(grid, r1, midRow, midCol + 1, c2);

        // Bottom Left
        root->bottomLeft =
            solve(grid, midRow + 1, r2, c1, midCol);

        // Bottom Right
        root->bottomRight =
            solve(grid, midRow + 1, r2, midCol + 1, c2);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid, 0, n - 1, 0, n - 1);
    }
};