class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int toprow = 0;
        int bottomrow = row - 1;

        // Find the correct row
        while (toprow <= bottomrow) {

            int midRow = (toprow + bottomrow) / 2;

            if (target > matrix[midRow][col - 1]) {
                toprow = midRow + 1;
            }
            else if (target < matrix[midRow][0]) {
                bottomrow = midRow - 1;
            }
            else {
                break;
            }
        }

        if (toprow > bottomrow)
            return false;

        int rowIndex = (toprow + bottomrow) / 2;

        int l = 0;
        int right = col - 1;

        while (l <= right) {

            int mid = (l + right) / 2;

            if (target > matrix[rowIndex][mid]) {
                l = mid + 1;
            }
            else if (target < matrix[rowIndex][mid]) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};