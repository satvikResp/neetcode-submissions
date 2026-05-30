class Solution {
public:

    bool validbox(vector<vector<char>>& board,
                  int sr, int er,
                  int sc, int ec) {

        unordered_set<char> boxdigit;

        for (int row = sr; row <= er; row++) {
            for (int col = sc; col <= ec; col++) {

                if (board[row][col] == '.') continue;

                char digit = board[row][col];

                if (boxdigit.count(digit)) {
                    return false;
                }

                boxdigit.insert(digit);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

         
        for (int i = 0; i < board.size(); i++) {

            unordered_set<char> rowele;

            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == '.') continue;

                char digit = board[i][j];

                if (rowele.count(digit)) {
                    return false;
                }

                rowele.insert(digit);
            }
        }

         
        for (int j = 0; j < board[0].size(); j++) {

            unordered_set<char> colele;

            for (int i = 0; i < board.size(); i++) {

                if (board[i][j] == '.') continue;

                char digit = board[i][j];

                if (colele.count(digit)) {
                    return false;
                }

                colele.insert(digit);
            }
        }

        
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[0].size(); j += 3) {

                int sr = i;
                int er = i + 2;

                int sc = j;
                int ec = j + 2;

                if (!validbox(board, sr, er, sc, ec)) {
                    return false;
                }
            }
        }

        return true;
    }
};