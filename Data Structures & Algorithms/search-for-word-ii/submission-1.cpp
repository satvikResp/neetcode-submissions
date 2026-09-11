class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
public:

    void func(vector<vector<char>>& board,
              TrieNode* curr,
              int row,
              int col,
              vector<string>& ans) {

        
        int idx = board[row][col] - 'a';
        // current board character Trie mein exist nahi karta
        if(curr->children[idx] == nullptr) {
            return;
        }

        curr = curr->children[idx];

        // poora word mil gaya
        if(curr->word != "") {
            ans.push_back(curr->word);

            // same word dobara na aaye
            curr->word = "";
        }

        // current cell ko visited mark
        char temp = board[row][col];
        board[row][col] = '#';

        // LEFT
        if(col - 1 >= 0 && board[row][col - 1] != '#') {
            func(board, curr, row, col - 1, ans);
        }

        // RIGHT
        if(col + 1 < board[0].size() && board[row][col + 1] != '#') {
            func(board, curr, row, col + 1, ans);
        }

        // TOP
        if(row - 1 >= 0 && board[row - 1][col] != '#') {
            func(board, curr, row - 1, col, ans);
        }

        // BOTTOM
        if(row + 1 < board.size() && board[row + 1][col] != '#') {
            func(board, curr, row + 1, col, ans);
        }

        // backtrack
        board[row][col] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        vector<string> ans;

        // ---------------- Trie banana ----------------

        TrieNode* root = new TrieNode();

        for(auto word : words) {

            TrieNode* curr = root;

            for(int i = 0; i < word.size(); i++) {

                int idx = word[i] - 'a';

                if(curr->children[idx] == nullptr) {
                    curr->children[idx] = new TrieNode();
                }

                curr = curr->children[idx];
            }

            curr->word = word;
        }

        // ---------------- Board DFS ----------------

        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                func(board, root, i, j, ans);
            }
        }

        return ans;
    }
};